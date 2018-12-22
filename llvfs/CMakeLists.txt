# -*- cmake -*-

project(llvfs)

include(LLCommon)

include_directories(
    ${LLCOMMON_INCLUDE_DIRS}
    ${LLCOMMON_SYSTEM_INCLUDE_DIRS}
    )

set(llvfs_SOURCE_FILES
    lldir.cpp
    lldiriterator.cpp
    lllfsthread.cpp
    llpidlock.cpp
    llvfile.cpp
    llvfs.cpp
    llvfsthread.cpp
    )

set(llvfs_HEADER_FILES
    CMakeLists.txt

    lldir.h
    lldirguard.h
    lldiriterator.h
    lllfsthread.h
    llpidlock.h
    llvfile.h
    llvfs.h
    llvfsthread.h
    )

if (DARWIN)
  LIST(APPEND llvfs_SOURCE_FILES lldir_mac.cpp)
  LIST(APPEND llvfs_HEADER_FILES lldir_mac.h)
  LIST(APPEND llvfs_SOURCE_FILES llvfs_objc.mm)
  LIST(APPEND llvfs_HEADER_FILES llvfs_objc.h)
endif (DARWIN)

if (LINUX)
  LIST(APPEND llvfs_SOURCE_FILES lldir_linux.cpp)
  LIST(APPEND llvfs_HEADER_FILES lldir_linux.h)

  if (INSTALL)
    set_source_files_properties(lldir_linux.cpp
                                PROPERTIES COMPILE_FLAGS
                                "-DAPP_RO_DATA_DIR=\\\"${APP_SHARE_DIR}\\\""
                                )
  endif (INSTALL)
endif (LINUX)

if (WINDOWS)
  LIST(APPEND llvfs_SOURCE_FILES lldir_win32.cpp)
  LIST(APPEND llvfs_HEADER_FILES lldir_win32.h)
endif (WINDOWS)

set_source_files_properties(${llvfs_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llvfs_SOURCE_FILES ${llvfs_HEADER_FILES})

add_library (llvfs ${llvfs_SOURCE_FILES})

set(vfs_BOOST_LIBRARIES
    ${BOOST_FILESYSTEM_LIBRARY}
    ${BOOST_SYSTEM_LIBRARY}
    )

target_link_libraries(llvfs
    ${LLCOMMON_LIBRARIES}
    ${vfs_BOOST_LIBRARIES}
    )

if (DARWIN)
  include(CMakeFindFrameworks)
  find_library(COCOA_LIBRARY Cocoa)
  target_link_libraries(llvfs ${COCOA_LIBRARY})
endif (DARWIN)

