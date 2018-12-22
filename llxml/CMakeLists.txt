# -*- cmake -*-

project(llxml)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
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
find_package(expat)

target_link_libraries(
    llxml PUBLIC
    llvfs
    llmath
    llcommon
    expat::expat
#    ${LLVFS_LIBRARIES}
#    ${LLMATH_LIBRARIES}
#    ${LLCOMMON_LIBRARIES}
#    ${EXPAT_LIBRARIES}
    )

