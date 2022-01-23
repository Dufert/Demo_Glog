project(demo_glog)
find_package (glog REQUIRED)

add_executable(${PROJECT_NAME}_main ./demo_glog.cpp)

target_link_libraries(${PROJECT_NAME}_main
    glog
)