#pragma once

#include <string_view>

namespace kitten {

#ifndef DISABLE_TRACING
#define TRACE_SCOPE ScopedTrace __traceMarker__##__LINE__(__FILE__, __func__, __LINE__)
#define TRACE_SET_THREAD_NAME(name) setTraceThreadName(name)
#else
#define TRACE_SCOPE
#define TRACE_SET_THREAD_NAME(name) 
#endif

struct TraceMarker;

class ScopedTrace {
public:
    ScopedTrace(std::string_view file, std::string_view func, int line);
    ~ScopedTrace();
private:
    TraceMarker* m_marker;
};

void setTraceThreadName(std::string_view name);

void saveCollectedTracing(std::string_view filename);

}
