set(NAME kitten_logger)

file (GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)

add_library(${NAME} ${srcs})
target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(${NAME} ${Boost_LIBRARIES} boost_stacktrace_backtrace dl backtrace)
target_compile_definitions(${NAME} PUBLIC
    -DELPP_THREAD_SAFE
    -DELPP_FEATURE_CRASH_LOG
    -DELPP_NO_LOG_TO_FILE
    -DELPP_NO_DEFAULT_LOG_FILE)

