add_library(kitten_logger INTERFACE)
target_include_directories(kitten_logger INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS system log)
target_link_libraries(kitten_logger INTERFACE ${Boost_LIBRARIES})
