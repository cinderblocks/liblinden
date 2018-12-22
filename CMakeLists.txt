cmake_minimum_required(VERSION 3.13)
project(liblinden)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

add_subdirectory(cmake)
add_subdirectory(llcommon)
#add_subdirectory(llappearance)
add_subdirectory(llcharacter)
add_subdirectory(llinventory)
add_subdirectory(llmath)
add_subdirectory(llmessage)
add_subdirectory(llprimitive)
add_subdirectory(llvfs)
add_subdirectory(llxml)

IF (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
            "Build type. One of: Debug Release RelWithDebInfo" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

#ucm_set_runtime(STATIC)

find_package(Threads REQUIRED)

set(liblinden_SOURCE_FILES
    liblinden.cpp
    )

set(liblinden_HEADER_FILES
    liblinden.h
    )

list(APPEND liblinden_SOURCE_FILES ${liblinden_HEADER_FILES})
set_source_files_properties(${liblinden_HEADER_FILES}
    PROPERTIES HEADER_FILE_ONLY TRUE )

add_definitions(-DNO_PRECOMPILED_HEADERS)
add_library(liblinden STATIC ${liblinden_SOURCE_FILES})
