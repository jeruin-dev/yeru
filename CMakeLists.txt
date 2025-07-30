cmake_minimum_required(VERSION 3.21)

project(app LANGUAGES CXX VERSION 1.0.0)

add_executable(${PROJECT_NAME} src/main.cc)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------------------------------------
# Link libraries
# --------------------------------------------------------------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    saucer
    GIT_REPOSITORY "https://github.com/saucer/saucer"
    GIT_TAG v6.0.1
)

FetchContent_MakeAvailable(saucer)

target_link_libraries(${PROJECT_NAME} PRIVATE saucer::saucer)
