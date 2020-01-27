#pragma once

#include <iostream>
#include <string_view>
#include <sstream>

namespace kitten {

enum class LogLevel {
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Fatal,
};

class LogMessage {
public:
    LogMessage(std::string_view fileName, std::string funcName, int line, LogLevel level) {
        switch (level)
        {
        case LogLevel::Trace:
            m_stream << "TRC [";
            break;
        case LogLevel::Debug:
            m_stream << "DBG [";
            break;
        case LogLevel::Info:
            m_stream << "INF [";
            break;
        case LogLevel::Warning:
            m_stream << "WRN [";
            break;
        case LogLevel::Error:
            m_stream << "ERR [";
            break;
        case LogLevel::Fatal:
            m_stream << "FTL [";
            break;
        default:
            break;
        }
        m_stream << fileName << ":" << line << "] ";
    }

    ~LogMessage() {
        m_stream << std::endl;
        std::cout << m_stream.str();
    }

    template <typename T>
    LogMessage& operator<<(const T& val) {
        m_stream << val;
        return *this;
    }

private:
    std::ostringstream m_stream;
};

}
