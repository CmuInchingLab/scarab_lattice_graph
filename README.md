# Scarab Lattice Graph helper classes

`
git clone https://github.com/CmuInchingLab/scarab_lattice_graph.git
`

Main components are in `lattice_graph.cpp`, `lattice_graph.hpp`, `include/eigen_VERSION_HASH`.

## How to merge

Copy the files mentioned above into project repo, under that project's `CMakeLists.txt`,
insert something like these few lines to include Eigen and build with the new library.

`
set(eigen_INCLUDE_DIRS include/eigen-eigen-b3f3d4950030)
include_directories(${catkin_INCLUDE_DIRS} ${eigen_INCLUDE_DIRS})
add_executable(<YOUR_ORIGINAL_STUFF> lattice_graph.cpp)
`

Inside the your own `.cpp` or `.hpp` project code files, just include the header `lattice_graph.hpp`.

Then run `catkin_make`.

## How to use

Check out `main.cpp` for a few examples on how to create the object, and call for global/relative motion primitives.