cmake_minimum_required(VERSION 3.0.2)
project(test1_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib
)
 
include_directories(
  ${catkin_INCLUDE_DIRS}
)
 
add_executable(hello_world_node src/hello_world_node.cpp)
add_dependencies(hello_world_node test1_pkg_generate_messages_cpp)
target_link_libraries(hello_world_node ${catkin_LIBRARIES})

