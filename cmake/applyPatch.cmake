include(FindPatch)

MACRO(APPLY_PATCH_IF_NEEDED markerFile patchFile subdir description)
IF(NOT EXISTS "${subdir}/${markerFile}")
    MESSAGE(STATUS "Patching file in ${subdir} ${description}")
    MESSAGE(STATUS " patch_file_p(1::: ${subdir}::: ${CMAKE_SOURCE_DIR}/patches/${patchFile}")
    patch_file_p(1 "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}" "${CMAKE_SOURCE_DIR}/patches/${patchFile}")
    file(WRITE "${subdir}/${markerFile}" "patched")
ENDIF(NOT EXISTS "${subdir}/${markerFile}")
ENDMACRO(APPLY_PATCH_IF_NEEDED markerFile patchFile subdir description)
