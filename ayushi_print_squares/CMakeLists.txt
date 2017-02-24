cmake_minimum_required(VERSION 2.8.3)
project(ayushi_print_squares)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(numbers_ayushi src/numbers_ayushi.cpp)
add_executable(squares_ayushi src/squares_ayushi.cpp)
add_executable(print_ayushi src/print_ayushi.cpp)

target_link_libraries(numbers_ayushi ${catkin_LIBRARIES})  
target_link_libraries(squares_ayushi ${catkin_LIBRARIES})
target_link_libraries(print_ayushi ${catkin_LIBRARIES})


