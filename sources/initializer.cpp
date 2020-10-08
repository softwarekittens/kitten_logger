#include "kitten_logger/logger.h"

#include <boost/stacktrace.hpp>

INITIALIZE_EASYLOGGINGPP

namespace {

#ifndef WITHOUT_CRASH_HANDLER
void crashHandler(int sig) {
    printf("Woops! Crashed! signal %d\n", sig);
    std::stringstream ss;
    ss <<  boost::stacktrace::stacktrace();
    printf("%s", ss.str().c_str());
    // FOLLOWING LINE IS ABSOLUTELY NEEDED AT THE END IN ORDER TO ABORT APPLICATION
    exit(1);
}
#endif //WITHOUT_CRASH_HANDLER

struct LoggerInitializer {
    LoggerInitializer() {
        el::Configurations defaultConf;
        defaultConf.setToDefault();
        defaultConf.setGlobally(el::ConfigurationType::Format, "[%datetime{%Y-%M-%d %H:%m:%s.%g}] [%thread] [%level] [%fbase:%line] %msg");
        el::Loggers::reconfigureLogger("default", defaultConf);
#ifndef WITHOUT_CRASH_HANDLER
        el::Helpers::setCrashHandler(crashHandler);
#endif //WITHOUT_CRASH_HANDLER
    }
};

LoggerInitializer g_logger;

}











