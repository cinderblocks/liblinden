# -*- cmake -*-

project(llprimitive)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
#include(LLCommon)
#include(LLMath)
#include(LLMessage)
#include(LLCoreHttp)
#include(LLXML)
#include(LLCharacter)

set(llprimitive_SOURCE_FILES
    lldaeloader.cpp
    llmaterialid.cpp
    llmaterial.cpp
    llmaterialtable.cpp
    llmediaentry.cpp
    llmodel.cpp
    llmodelloader.cpp
    llprimitive.cpp
    llprimtexturelist.cpp
    lltextureanim.cpp
    lltextureentry.cpp
    lltreeparams.cpp
    llvolumemessage.cpp
    material_codes.cpp
    )

set(llprimitive_HEADER_FILES
    CMakeLists.txt
    lldaeloader.h
    legacy_object_types.h
    llmaterial.h
    llmaterialid.h
    llmaterialtable.h
    llmediaentry.h
    llmodel.h
    llmodelloader.h
    llprimitive.h
    llprimtexturelist.h
    lllslconstants.h
    lltextureanim.h
    lltextureentry.h
    lltreeparams.h
    lltree_common.h
    llvolumemessage.h
    material_codes.h
    object_flags.h
    )
        
set_source_files_properties(${llprimitive_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llprimitive_SOURCE_FILES ${llprimitive_HEADER_FILES})

add_library (llprimitive ${llprimitive_SOURCE_FILES})

target_link_libraries(llprimitive
    llcommon
    llmath
    llmessage
    llcorehttp
    llxml
    llcharacter
#    ${LLCOMMON_LIBRARIES}
#    ${LLMATH_LIBRARIES}
#    ${LLMESSAGE_LIBRARIES}
#    ${LLCOREHTTP_LIBRARIES}
#    ${LLXML_LIBRARIES}
#    ${LLPHYSICSEXTENSIONS_LIBRARIES}
#    ${LLCHARACTER_LIBRARIES}
#    ${BOOST_COROUTINE_LIBRARY}
#    ${BOOST_CONTEXT_LIBRARY}
    )

