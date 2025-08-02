cmake_minimum_required(VERSION 3.24)

project(app LANGUAGES CXX VERSION 1.0.0)

add_executable(${PROJECT_NAME} source/src/main.cc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(saucer_serializer "Rflpp")

# Debug configuration
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=x86-64 -mno-avx -DNDEBUG")

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------------------------------------
# Link libraries
# --------------------------------------------------------------------------------------------------------


include(cmake/CPM.cmake)


CPMAddPackage(
  NAME           saucer
  VERSION        6.0.1
  GIT_REPOSITORY "https://github.com/saucer/saucer"
)

FetchContent_MakeAvailable(saucer)

target_link_libraries(${PROJECT_NAME} PRIVATE saucer::saucer)
