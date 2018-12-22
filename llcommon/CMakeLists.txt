
# -*- cmake -*-

project(llcommon)

include(../conanbuildinfo.cmake)
#include(LLCommon)
#include(Boost)
#include(JsonCpp)
#include(ZLIB)
#include(URIPARSER)

set(llcommon_SOURCE_FILES
    indra_constants.cpp
    llallocator.cpp
    llallocator_heap_profile.cpp
    llapp.cpp
    llapr.cpp
    llassettype.cpp
    llbase32.cpp
    llbase64.cpp
    llbitpack.cpp
    llcallbacklist.cpp
    llcallstack.cpp
    llcleanup.cpp
    llcommon.cpp
    llcommonutils.cpp
    llcoro_get_id.cpp
    llcoros.cpp
    llcrc.cpp
    llcriticaldamp.cpp
    lldate.cpp
    lldeadmantimer.cpp
    lldependencies.cpp
    lldictionary.cpp
    llerror.cpp
    llerrorthread.cpp
    llevent.cpp
    lleventapi.cpp
    lleventcoro.cpp
    lleventdispatcher.cpp
    lleventfilter.cpp
    llevents.cpp
    lleventtimer.cpp
    llexception.cpp
    llfasttimer.cpp
    llfile.cpp
    llfindlocale.cpp
    llfixedbuffer.cpp
    llformat.cpp
    llframetimer.cpp
    llheartbeat.cpp
    llheteromap.cpp
    llinitparam.cpp
    llinitdestroyclass.cpp
    llinstancetracker.cpp
    llleap.cpp
    llleaplistener.cpp
    llliveappconfig.cpp
    lllivefile.cpp
    llmd5.cpp
    llmemory.cpp
    llmemorystream.cpp
    llmetrics.cpp
    llmetricperformancetester.cpp
    llmortician.cpp
    llmutex.cpp
    llptrto.cpp 
    llpredicate.cpp
    llprocess.cpp
    llprocessor.cpp
    llprocinfo.cpp
    llqueuedthread.cpp
    llrand.cpp
    llrefcount.cpp
    llrun.cpp
    llsd.cpp
    llsdjson.cpp
    llsdparam.cpp
    llsdserialize.cpp
    llsdserialize_xml.cpp
    llsdutil.cpp
    llsingleton.cpp
    llstacktrace.cpp
    llstreamqueue.cpp
    llstreamtools.cpp
    llstring.cpp
    llstringtable.cpp
    llsys.cpp
    llthread.cpp
    llthreadlocalstorage.cpp
    llthreadsafequeue.cpp
    lltimer.cpp
    lltrace.cpp
    lltraceaccumulators.cpp
    lltracerecording.cpp
    lltracethreadrecorder.cpp
    lluri.cpp
    lluriparser.cpp
    lluuid.cpp
    llworkerthread.cpp
    timing.cpp
    u64.cpp
    StackWalker.cpp
    )
    
set(llcommon_HEADER_FILES
    CMakeLists.txt

    ctype_workaround.h
    fix_macros.h
    indra_constants.h
    linden_common.h
    llalignedarray.h
    llallocator.h
    llallocator_heap_profile.h
    llapp.h
    llapr.h
    llassettype.h
    llbase32.h
    llbase64.h
    llbitpack.h
    llboost.h
    llcallbacklist.h
    llcallstack.h
    llcleanup.h
    llcommon.h
    llcommonutils.h
    llcoro_get_id.h
    llcoros.h
    llcrc.h
    llcriticaldamp.h
    lldate.h
    lldeadmantimer.h
    lldefs.h
    lldependencies.h
    lldepthstack.h
    lldictionary.h
    lldoubledispatch.h
    llendianswizzle.h
    llerror.h
    llerrorcontrol.h
    llerrorthread.h
    llevent.h
    lleventapi.h
    lleventcoro.h
    lleventdispatcher.h
    lleventfilter.h
    llevents.h
    lleventemitter.h
    llexception.h
    llfasttimer.h
    llfile.h
    llfindlocale.h
    llfixedbuffer.h
    llformat.h
    llframetimer.h
    llhandle.h
    llhash.h
    llheartbeat.h
    llheteromap.h
    llindexedvector.h
    llinitdestroyclass.h
    llinitparam.h
    llinstancetracker.h
    llkeythrottle.h
    llleap.h
    llleaplistener.h
    lllistenerwrapper.h
    llliveappconfig.h
    lllivefile.h
    llmd5.h
    llmemory.h
    llmemorystream.h
    llmetrics.h
    llmetricperformancetester.h
    llmortician.h
    llnametable.h
    llpointer.h
    llpounceable.h
    llpredicate.h
    llpreprocessor.h
    llpriqueuemap.h
    llprocess.h
    llprocessor.h
    llprocinfo.h
    llptrto.h
    llqueuedthread.h
    llrand.h
    llrefcount.h
    llregistry.h
    llrun.h
    llrefcount.h
    llsafehandle.h
    llsd.h
    llsdjson.h
    llsdparam.h
    llsdserialize.h
    llsdserialize_xml.h
    llsdutil.h
    llsimplehash.h
    llsingleton.h
    llstacktrace.h
    llstl.h
    llstreamqueue.h
    llstreamtools.h
    llstrider.h
    llstring.h
    llstringtable.h
    llstaticstringtable.h
    llstatsaccumulator.h
    llsys.h
    llthread.h
    llthreadlocalstorage.h
    llthreadsafequeue.h
    lltimer.h
    lltrace.h
    lltraceaccumulators.h
    lltracerecording.h
    lltracethreadrecorder.h
    lltreeiterators.h
    llunits.h
    llunittype.h
    lluri.h
    lluriparser.h
    lluuid.h
    llwin32headers.h
    llwin32headerslean.h
    llworkerthread.h
    stdtypes.h
    stringize.h
    timer.h
    u64.h
    StackWalker.h
    )

set_source_files_properties(${llcommon_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND llcommon_SOURCE_FILES ${llcommon_HEADER_FILES})

add_library (llcommon ${llcommon_SOURCE_FILES})

target_link_libraries(
    llcommon
    ${CONAN_LIBS}
#    ${APRUTIL_LIBRARIES}
#    ${APR_LIBRARIES}
#    ${EXPAT_LIBRARIES}
#    ${JSONCPP_LIBRARIES}
#    ${ZLIB_LIBRARIES}
#    ${WINDOWS_LIBRARIES}
#    ${BOOST_COROUTINE_LIBRARY}
#    ${BOOST_CONTEXT_LIBRARY}
#    ${BOOST_PROGRAM_OPTIONS_LIBRARY}
#    ${BOOST_REGEX_LIBRARY}
#    ${BOOST_SYSTEM_LIBRARY}
#    ${GOOGLE_PERFTOOLS_LIBRARIES}
#    ${URIPARSER_LIBRARIES}
    )

