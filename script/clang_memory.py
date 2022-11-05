#!/usr/bin/env python3
# MIT License
#
# Copyright (c) 2016 Scott Shawcroft for Adafruit Industries
# Copyright (c) 2018 Ralph Versteegen
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

from __future__ import print_function

import sys
import os
import argparse


SECTION_NONE = 0
SECTION_RAM = 1
SECTION_CODE= 2
SECTION_INITIALIZED_RAM = 3
SECTION_MAX = 4

section_names=["None","RAM","Code","InitRam"]

parser = argparse.ArgumentParser(description='Summarises the size of each object file in an ld linker map.')
parser.add_argument('map_file', help="A map file generated by passing -M/--print-map to ld during linking.")
parser.add_argument('--combine', action='store_true',
                    help="All object files in an .a archive or in a directory are combined")
args = parser.parse_args()

class SectionSize():
    code = 0
    data = 0  # Including metadata like import tables
    def total(self):
        return self.code + self.data
    def add_section(self, section, size):
        if section.startswith('.comment'):
            return
        if section.startswith('.debug'):
            return
        if section.startswith('.ARM.attributes'):
            return
        if section.startswith('.text'):
            self.code += size
        elif section != '.bss':
            self.data += size

size_by_source = {}
sums = [0] * 5
with open(args.map_file) as f:
    lines = iter(f)
    current_section = None
    split_line = None
    for line in lines:
        line = line.strip('\n')
        #print(line)
        if(line.find(".debug") != -1):
           continue
        if(line.find(".o")==-1):
           continue
        #  8000000  8000000       10     1         CMakeFiles/lnPowerSupply.dir/lnArduino/arm_gd32fx/vector_table.S.obj:(.stm32.interrupt_vector)
        pieces = line.split(None,5)
        #print(pieces) 
        size = int(pieces[2],16)
        #print(size)
        source= pieces[4]
        target  = SECTION_NONE
        if source.find(".bss")!=-1:
            target= SECTION_RAM
        elif source.find(".rodata")!=-1 or source.find(".text")!=-1:
            target= SECTION_CODE
        elif source.find(".data")!=-1 :
            target= SECTION_INITIALIZED_RAM
        if target is SECTION_NONE:
            continue
        #print(section_names[target])
        sums[target] +=  size
f.close()
# Print out summary
for i in range(1,SECTION_MAX):
        print("%s\t %d \t(%d kB)" % (section_names[i], sums[i],(sums[i]+511)/1024))
