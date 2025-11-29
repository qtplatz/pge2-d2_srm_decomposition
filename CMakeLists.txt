cmake_minimum_required(VERSION 3.30)

project( pge2-d2_srm_decomposition )
set ( CMAKE_EXPORT_COMPILE_COMMANDS ON )

find_package( Eigen3 REQUIRED NO_MODULE)

set( CMAKE_CXX_STANDARD 20 )

include_directories(
  ${EIGEN3_INCLUDE_DIR}
)

add_executable( ${PROJECT_NAME}
  main.cpp peakd.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
