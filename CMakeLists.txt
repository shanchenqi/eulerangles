#cmake_minimum_required(VERSION 3.1)
#set(CMAKE_CXX_STANDARD 11)
#project(opencv_example_project)
#find_package(OpenCV 4.4 REQUIRED)
#link_directories("/usr/local/opencv4.4/lib/")

#include_directories("/usr/local/opencv4.4/include/opencv4")
#message( "OpenCV library status:")
#message("    config: ${OpenCV_DIR}")
#message(STATUS "    version: ${OpenCV_VERSION}")
#message(STATUS "    libraries: ${OpenCV_LIBS}")
#message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

#add_executable(test_ccm test_ccm1.cpp)
#target_link_libraries(test_ccm opencv_core opencv_mcc opencv_highgui opencv_imgcodecs)


# cmake needs this line
cmake_minimum_required(VERSION 3.1)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lgtest")
# Define project name
project(opencv_example_project)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
set(OpenCV_DIR /usr/local/opencv4.4/lib/cmake/opencv4)
link_directories("/usr/local/opencv4.4/lib/")
link_libraries(opencv_mcc)
find_package(OpenCV 4 REQUIRED)
find_package(GTest REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS} )
# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message( "OpenCV library status:")
#message("    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Declare the executable target built from your sources
#add_executable(unitest unitest.cpp)
# Link your application with OpenCV libraries
#target_link_libraries(unitest opencv_core opencv_mcc opencv_highgui opencv_imgcodecs opencv_ts ${GTEST_BOTH_LIBRARIES} pthread)
add_executable(test_angle Euler_angles.cpp)
target_link_libraries(test_angle opencv_core opencv_mcc opencv_highgui opencv_imgcodecs)
#gtest_discover_tests(unitest)


