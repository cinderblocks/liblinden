# -*- cmake -*-

project(llinventory)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(llinventory_SOURCE_FILES
    llcategory.cpp
    lleconomy.cpp
    llfoldertype.cpp
    llinventory.cpp
    llinventorydefines.cpp
    llinventorytype.cpp
    lllandmark.cpp
    llnotecard.cpp
    llparcel.cpp
    llpermissions.cpp
    llsaleinfo.cpp
    lltransactionflags.cpp
    lluserrelations.cpp
    )
    
set(llinventory_HEADER_FILES
    CMakeLists.txt

    llcategory.h
    lleconomy.h
    llfoldertype.h
    llinventory.h
    llinventorydefines.h
    llinventorytype.h
    lllandmark.h
    llnotecard.h
    llparcel.h
    llparcelflags.h
    llpermissions.h
    llpermissionsflags.h
    llsaleinfo.h
    lltransactionflags.h
    lltransactiontypes.h
    lluserrelations.h
    )

set_source_files_properties(${llinventory_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llinventory_SOURCE_FILES ${llinventory_HEADER_FILES})

add_library(llinventory ${llinventory_SOURCE_FILES})
target_include_directories(llinventory PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(
    llinventory PUBLIC
    llcommon
    llmessage
    )
