
cmake_minimum_required (VERSION 2.6)
project(main)

#ADD_DEFINITIONS(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ADD_DEFINITIONS(-g)


set(glbinding_DIR ../glbinding)
find_package(glbinding REQUIRED) # if it is really required in your project


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(../glfw ./glfwbuildtmp)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC glfw glbinding::glbinding)






