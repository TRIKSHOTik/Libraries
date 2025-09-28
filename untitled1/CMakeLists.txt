cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../library")

add_library(Number STATIC IMPORTED)
set_target_properties(Number PROPERTIES
        IMPORTED_LOCATION "${LIBRARY_DIR}/build_vs_debug/lib/Debug/Number.lib"
)

add_library(Vector SHARED IMPORTED)

set_target_properties(Vector PROPERTIES
        IMPORTED_LOCATION "${LIBRARY_DIR}/build_vs_debug/bin/Debug/Vector.dll"
        IMPORTED_IMPLIB "${LIBRARY_DIR}/build_vs_debug/lib/Debug/Vector.dll"
)

include_directories("${LIBRARY_DIR}/include")

add_executable(test main.cpp)
target_link_libraries(test Number Vector)

add_custom_command(TARGET test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:test>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${LIBRARY_DIR}/build_vs_debug/bin/Debug/Vector.dll"
        $<TARGET_FILE_DIR:test>
)