cmake_minimum_required(VERSION 2.8)
project(slamDemo)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")

# find_package(OpenCV 4 REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})

SET(EIGEN_INCLUDE_DIR "/usr/include/eigen3")
include_directories(${EIGEN_INCLUDE_DIR}
                    ${PROJECT_SOURCE_DIR}/include)

# find_package(yaml-cpp REQUIRED)
# include_directories(${YAML_INCLUDE_DIRS})

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# set(SRC load_param.cpp)

# add_library(slamDemo SHARED ${SRC})
# target_link_libraries(slamDemo 
#                       ${YAML_CPP_LIBRARIES}
#                       ${OpenCV_LIBS} 
#                       )

add_executable(eigenTest app/eigenTest.cpp)
# target_link_libraries(eigenTest )