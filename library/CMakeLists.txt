cmake_minimum_required(VERSION 3.10)
project(Library)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Number STATIC src/Number.cpp include/Number.h)
add_library(Vector SHARED src/Vector.cpp include/Vector.h)

target_link_libraries(Vector PRIVATE Number)
target_compile_definitions(Vector PRIVATE VECTOR_EXPORTS)

set_target_properties(Number PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        PREFIX ""
        IMPORT_PREFIX ""
        IMPORT_SUFFIX ".lib"
)

set_target_properties(Vector PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        PREFIX ""
        IMPORT_PREFIX ""
        IMPORT_SUFFIX ".dll"
)

install(TARGETS Number Vector
        EXPORT MyLibrariesTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)