# -*- cmake -*-

project(llcorehttp)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
#include(CURL)
#include(OpenSSL)
#include(NGHTTP2)
#include(ZLIB)
#include(LLCoreHttp)
#include(LLMessage)
#include(LLCommon)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})

set(llcorehttp_SOURCE_FILES
    bufferarray.cpp
    bufferstream.cpp
    httpcommon.cpp
    llhttpconstants.cpp
    httpheaders.cpp
    httpoptions.cpp
    httprequest.cpp
    httpresponse.cpp
    httpstats.cpp
    _httplibcurl.cpp
    _httpopcancel.cpp
    _httpoperation.cpp
    _httpoprequest.cpp
    _httpopsetget.cpp
    _httpopsetpriority.cpp
    _httppolicy.cpp
    _httppolicyclass.cpp
    _httppolicyglobal.cpp
    _httpreplyqueue.cpp
    _httprequestqueue.cpp
    _httpservice.cpp
    _refcounted.cpp
    )

set(llcorehttp_HEADER_FILES
    CMakeLists.txt

    bufferarray.h
    bufferstream.h
    httpcommon.h
    llhttpconstants.h
    httphandler.h
    httpheaders.h
    httpoptions.h
    httprequest.h
    httpresponse.h
    httpstats.h
    _httpinternal.h
    _httplibcurl.h
    _httpopcancel.h
    _httpoperation.h
    _httpoprequest.h
    _httpopsetget.h
    _httpopsetpriority.h
    _httppolicy.h
    _httppolicyclass.h
    _httppolicyglobal.h
    _httpreadyqueue.h
    _httpreplyqueue.h
    _httprequestqueue.h
    _httpservice.h
    _mutex.h
    _refcounted.h
    _thread.h
    )

set_source_files_properties(${llcorehttp_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llcorehttp_SOURCE_FILES ${llcorehttp_HEADER_FILES})

add_library (llcorehttp ${llcorehttp_SOURCE_FILES})
target_include_directories(llcorehttp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

find_package(libcurl)
find_package(OpenSSL)

target_link_libraries(
  llcorehttp
  llcommon
  llmessage
  libcurl::libcurl
  OpenSSL::OpenSSL
#  ${CURL_LIBRARIES}
#  ${OPENSSL_LIBRARIES}
#  ${CRYPTO_LIBRARIES}
#  ${NGHTTP2_LIBRARIES}
#  ${BOOST_THREAD_LIBRARY}
#  ${BOOST_SYSTEM_LIBRARY}
  )

