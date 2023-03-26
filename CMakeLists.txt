cmake_minimum_required(VERSION 3.0.0)
project(face_detection VERSION 0.1.0)

include(CTest)
enable_testing()

# Find the OpenCV library
find_package(OpenCV 4.7.0 REQUIRED)


add_executable(face_detection main.cpp)

# Link the OpenCV library to the target
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
