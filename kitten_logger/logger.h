#pragma once

#include <boost/log/trivial.hpp>

#define POSTFIX "[" << __FILE__ << ":" << __LINE__ << ", " <<  __func__ << "] "
#define LOG_WRAPPER(level) BOOST_LOG_TRIVIAL(level) << POSTFIX

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
#define LOGT LOG_WRAPPER(trace)

// log debug level
#define LOGD LOG_WRAPPER(debug)

#endif

// log info level
#define LOGI LOG_WRAPPER(info)

// log warning level
#define LOGW LOG_WRAPPER(warning)

// log error level
#define LOGE LOG_WRAPPER(error)

// log fatal level
#define LOGF LOG_WRAPPER(fatal)
