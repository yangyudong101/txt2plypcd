cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(MY_GRAND_PROJECT)

find_package(PCL 1.8 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

include_directories(
    "/usr/include/vtk-7.1"
    "/usr/include/flann/"
    "/usr/includel/boost"
)

link_directories(
        "/usr/include"
)

add_executable(txt2pcd txt2pcd.cpp)
add_executable(pcd2txt pcd2txt.cpp)
target_link_libraries(txt2pcd ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES}) 
target_link_libraries(pcd2txt ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

# add_executable(main main.cpp)
# target_link_libraries(main ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})