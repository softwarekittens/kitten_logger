#pragma once

#include <boost/log/trivial.hpp>

#define POSTFIX __FILE__ << " : " <<  __func__ << " : " << __LINE__
#define LOG_WRAPPER(level) BOOST_LOG_TRIVIAL(level) << POSTFIX

// log trace level
#define LOGT LOG_WRAPPER(trace)

// log debug level
#define LOGD LOG_WRAPPER(debug)

// log info level
#define LOGI LOG_WRAPPER(info)

// log warning level
#define LOGW LOG_WRAPPER(warning)

// log error level
#define LOGE LOG_WRAPPER(error)

// log fatal level
#define LOGF LOG_WRAPPER(fatal)
