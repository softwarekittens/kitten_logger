file (GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
file (GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/kitten_logger/*.h)
add_library(kitten_logger ${sources} ${headers})

target_include_directories(kitten_logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS system log)
target_link_libraries(kitten_logger ${Boost_LIBRARIES})
