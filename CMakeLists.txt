cmake_minimum_required(VERSION 3.0.0)
project(IntMatrix VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(IntMatrix partA_tester.cpp Auxiliaries.cpp Auxiliaries.h IntMatrix.cpp IntMatrix.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
