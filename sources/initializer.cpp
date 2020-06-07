#include "kitten_logger/logger.h"

#include <boost/stacktrace.hpp>

INITIALIZE_EASYLOGGINGPP

namespace {

void crashHandler(int sig) {
    LOGE << "Woops! Crashed! signal " << sig;     
    LOGE << boost::stacktrace::stacktrace();
    // FOLLOWING LINE IS ABSOLUTELY NEEDED AT THE END IN ORDER TO ABORT APPLICATION
    el::Helpers::crashAbort(sig);
}

struct LoggerInitializer {
    LoggerInitializer() {
        el::Configurations defaultConf;
        defaultConf.setToDefault();
        defaultConf.setGlobally(el::ConfigurationType::Format, "[%datetime{%Y-%M-%d %H:%m:%s.%g}] [%thread] [%level] [%fbase:%line] %msg");
        el::Loggers::reconfigureLogger("default", defaultConf);
    }
};

LoggerInitializer g_logger;

}











