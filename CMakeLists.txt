cmake_minimum_required(VERSION 2.8.3)
project(scarab_lattice_graph)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  COMPONENTS
  roscpp
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package()

# executable and include directories
set(eigen_INCLUDE_DIRS include/eigen-eigen-b3f3d4950030)
include_directories(${catkin_INCLUDE_DIRS} ${eigen_INCLUDE_DIRS})
add_executable(lattice_graph main.cpp lattice_graph.cpp)
