#include "lnRingBuffer.h"

#define M(x) usartMapping[instance].x

/**
 */
#include "lnDma.h"
/**
 * @brief
 *
 */
class lnSerialBpTxOnlyDma : public lnSerialBpCore, public lnSerialTxOnly
{
  public:
    lnSerialBpTxOnlyDma(int instance, int txBufferSize);

    bool init()
    {
        return lnSerialBpCore::init();
    }
    bool setSpeed(int speed)
    {
        return lnSerialBpCore::setSpeed(speed);
    }
    virtual bool rawWrite(int count, const uint8_t *buffer)
    {
        LN_USART_Registers *d = (LN_USART_Registers *)_adr;
        return ln_serial_rawWrite(d, count, buffer);
    }
    virtual bool transmit(int size, const uint8_t *buffer);
    virtual void _interrupt(void)
    {
        xAssert(0);
    }
    bool transmitMe(int size, const uint8_t *buffer, lnDMA::doneCallback *c);
    virtual bool _programTx();
    static void _dmaCallback2(void *c, lnDMA::DmaInterruptType it);
    void txDmaCb2(lnDMA::DmaInterruptType it);
    void igniteTx();
    lnDMA _txDma;
    int _inFlight;
    lnRingBuffer _txRingBuffer;
    lnBinarySemaphore _txRingSem;
    bool _txing;
};
/**
 * @brief
 *
 * @return true
 * @return false
 */
bool lnSerialBpTxOnlyDma::_programTx()
{
    LN_USART_Registers *d = (LN_USART_Registers *)_adr;
    d->CTL0 &= ~LN_USART_CTL0_UEN;
    switch (_txState)
    {
    case txTransmittingDMA:
        disableInterrupt();
        d->CTL0 |= (LN_USART_CTL0_TBIE + LN_USART_CTL0_TCIE);
        d->CTL0 |= LN_USART_CTL0_TEN;    // enable TX
        d->CTL2 |= LN_USART_CTL2_DMA_TX; // enable TX DMA
        enableInterrupt(false, false);
        break;
    default:
        xAssert(0);
        break;
    }
    d->CTL0 |= LN_USART_CTL0_UEN;
    return true;
}

/**
 * @brief Construct a new ln Serial Bp Tx Only Dma object
 *
 * @param instance
 */
lnSerialBpTxOnlyDma::lnSerialBpTxOnlyDma(int instance, int txBufferSize)
    : lnSerialTxOnly(instance), lnSerialBpCore(instance),
      _txDma(lnDMA::DMA_MEMORY_TO_PERIPH, M(dmaEngine), M(dmaTxChannel), 8, 32), _txRingBuffer(txBufferSize)
{
}

/**
 * @brief
 *
 * @param size
 * @param buffer
 * @param c
 * @return true
 * @return false
 */
bool lnSerialBpTxOnlyDma::transmitMe(int size, const uint8_t *buffer, lnDMA::doneCallback *c) //_dmaCallback
{
    // return true;
    LN_USART_Registers *d = (LN_USART_Registers *)_adr;
    _txMutex.lock();        // lock uart
    _txDma.beginTransfer(); // lock dma
    ENTER_CRITICAL();
    _txState = txTransmittingDMA;
    _programTx();
    d->STAT &= ~LN_USART_STAT_TC;
    _txDma.attachCallback(c, this);
    EXIT_CRITICAL();

    _txDma.doMemoryToPeripheralTransferNoLock(size, (uint16_t *)buffer, (uint16_t *)&(d->DATA), false);

    _txDone.take();
    _txDma.endTransfer();

    // Wait busy bit to clear out
    while (!(d->STAT & LN_USART_STAT_TC))
    {
        __asm__("nop" ::);
    }
    d->STAT &= ~(LN_USART_STAT_TC);

    _txMutex.unlock();
    return true;
}

/**
 * @brief
 *
 * @param c
 * @param it
 */

void lnSerialBpTxOnlyDma::_dmaCallback2(void *c, lnDMA::DmaInterruptType it)
{
    lnSerialBpTxOnlyDma *i = (lnSerialBpTxOnlyDma *)c;
    i->txDmaCb2(it);
}
/**
 * @brief
 *
 * @param it
 */
void lnSerialBpTxOnlyDma::txDmaCb2(lnDMA::DmaInterruptType it)
{
    uint8_t *to;
    _txRingBuffer.consume(_inFlight);
    _inFlight = 0;
    _txRingSem.give(); // space freed, wake up thread

    int nb = _txRingBuffer.getReadPointer(&to);
    if (!nb) // done !
    {
        _txing = false;
        return;
    }
    // send remainer
    LN_USART_Registers *d = (LN_USART_Registers *)_adr;
    _inFlight = nb;
    _txDma.doMemoryToPeripheralTransferNoLock(nb, (uint16_t *)to, (uint16_t *)&(d->DATA), false);
}
/**
 * @brief
 *
 * @param size
 * @param buffer
 * @return true
 * @return false
 */
bool lnSerialBpTxOnlyDma::transmit(int size, const uint8_t *buffer)
{
    while (size)
    {
        ENTER_CRITICAL();
        int nb = _txRingBuffer.free();
        if (!nb)
        {
            _txRingSem.tryTake(); // wait for a fresh sem post, not an old one
            EXIT_CRITICAL();
            _txRingSem.take();
            continue;
        }
        if (nb > size)
            nb = size;
        _txRingBuffer.put(nb, buffer);
        buffer += nb, size -= nb;
        EXIT_CRITICAL();
        if (!_txing)
            igniteTx();
    }
    return true;
}
/**
 * @brief
 *
 */
void lnSerialBpTxOnlyDma::igniteTx() // if we get here, no active transer if going on
{
    uint8_t *to = NULL;
    int nb = _txRingBuffer.getReadPointer(&to);
    xAssert(nb);
    _inFlight = nb;
    _txing = true;
    LN_USART_Registers *d = (LN_USART_Registers *)_adr;
    _txDma.endTransfer();   // clear the previous one (if any)
    _txDma.beginTransfer(); // lock dma
    ENTER_CRITICAL();
    _txState = txTransmittingDMA;
    _programTx();
    d->STAT &= ~LN_USART_STAT_TC;
    _txDma.attachCallback(_dmaCallback2, this);
    EXIT_CRITICAL();

    _txDma.doMemoryToPeripheralTransferNoLock(nb, (uint16_t *)to, (uint16_t *)&(d->DATA), false);
}
// EOF