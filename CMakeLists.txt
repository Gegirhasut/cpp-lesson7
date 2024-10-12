cmake_minimum_required(VERSION 3.30)
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Matrixlib"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(MATH_USE_DOUBLE_PREC "Use double precision" ON)

set(sources
    src/matrix.h
    src/matrix.cpp
    src/export.h
    src/c/c_api.h
    src/c/c_api.cpp
)

include(GenerateExportHeader)

add_library(static-matrixlib STATIC ${sources})

target_include_directories(static-matrixlib
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_BINARY_DIR}>"
)

target_compile_definitions(
    static-matrixlib
    PUBLIC
        MATH_STATIC_DEFINE 1
        "$<$<BOOL:${MATH_USE_DOUBLE_PREC}>:MATH_DOUBLE_PREC_DEFINE>"
)

generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

add_library(shared-matrixlib SHARED ${sources})

target_include_directories(shared-matrixlib
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_BINARY_DIR}>"
)

generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)

target_compile_definitions(
    shared-matrixlib
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PREC}>:MATH_DOUBLE_PREC_DEFINE>"
)



add_executable(test-static-matrix
    src/test/test-static-matrix.cpp
)
target_include_directories(test-static-matrix
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-static-matrix PRIVATE static-matrixlib)


add_executable(test-shared-matrix
    src/test/test-shared-matrix.cpp
)
target_include_directories(test-shared-matrix
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-shared-matrix PRIVATE shared-matrixlib)