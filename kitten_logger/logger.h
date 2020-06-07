#pragma once

#ifndef BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
#define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
#endif //BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

#ifndef ELPP_THREAD_SAFE
#define ELPP_THREAD_SAFE 
#endif //ELPP_THREAD_SAFE

#ifndef ELPP_FEATURE_CRASH_LOG
#define ELPP_FEATURE_CRASH_LOG
#endif //ELPP_FEATURE_CRASH_LOG

#ifndef ELPP_NO_LOG_TO_FILE
#define ELPP_NO_LOG_TO_FILE
#endif //ELPP_NO_LOG_TO_FILE

#ifndef ELPP_NO_DEFAULT_LOG_FILE
#define ELPP_NO_DEFAULT_LOG_FILE
#endif //ELPP_NO_DEFAULT_LOG_FILE

#include "easylogging++.h"

#define LOG_POSTFIX "[" << __func__ << "] "

#define LOG_WRAPPER(LEVEL) LOG(LEVEL) << LOG_POSTFIX

#ifdef NDEBUG
struct EmptyLogLine {
    template <class T>
    EmptyLogLine& operator<< (const T&) {
        return *this;
    }
};

// log trace level
#define LOGT EmptyLogLine()

// log debug level
#define LOGD EmptyLogLine()

#else

// log trace level
#define LOGT LOG_WRAPPER(TRACE)

// log debug level
#define LOGD LOG_WRAPPER(DEBUG)

#endif

// log info level
#define LOGI LOG_WRAPPER(INFO)

// log warning level
#define LOGW LOG_WRAPPER(WARNING)

// log error level
#define LOGE LOG_WRAPPER(ERROR)

// log fatal level
#define LOGF LOG_WRAPPER(FATAL)

