# -*- cmake -*-

project(llxml)

include(../conanbuildinfo.cmake)
#include(LLCommon)
#include(LLMath)
#include(LLVFS)
#include(LLXML)

set(llxml_SOURCE_FILES
    llcontrol.cpp
    llxmlnode.cpp
    llxmlparser.cpp
    llxmltree.cpp
    )

set(llxml_HEADER_FILES
    CMakeLists.txt

    llcontrol.h
    llcontrolgroupreader.h
    llxmlnode.h
    llxmlparser.h
    llxmltree.h
    )

set_source_files_properties(${llxml_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llxml_SOURCE_FILES ${llxml_HEADER_FILES})

add_library (llxml ${llxml_SOURCE_FILES})
# Libraries on which this library depends, needed for Linux builds
# Sort by high-level to low-level
target_link_libraries( llxml
    ${CONAN_LIBS}
#    ${LLVFS_LIBRARIES}
#    ${LLMATH_LIBRARIES}
#    ${LLCOMMON_LIBRARIES}
#    ${EXPAT_LIBRARIES}
    )

