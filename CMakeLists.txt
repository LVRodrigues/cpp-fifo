cmake_minimum_required(VERSION 3.23.0)
project(cpp-fifo VERSION 1.0.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(PACKAGE_BUGREPORT "lvrodriguesline@gmail.com")

add_subdirectory(${CMAKE_SOURCE_DIR}/src/cpp-fifo-producer)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/cpp-fifo-consumer)

include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
