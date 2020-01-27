#pragma once

#include "log_message.h"

// scope trace
#define TRACE()

// log trace level
#define LOGT() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Trace)

// log debug level
#define LOGD() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Debug)

// log info level
#define LOGI() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Info)

// log warning level
#define LOGW() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Warning)

// log error level
#define LOGE() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Error)

// log fatal level
#define LOGF() kitten::LogMessage(__FILE__, __func__, __LINE__, kitten::LogLevel::Fatal)
