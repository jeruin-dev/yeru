cmake_minimum_required(VERSION 3.24)
project(app LANGUAGES CXX VERSION 1.0.0)

# -----------------------------------------------------
# Configuración de compilación
# -----------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Debug / Release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=x86-64 -mno-avx -DNDEBUG")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# -----------------------------------------------------
# Saucer - configuración de frontend embebido
# -----------------------------------------------------
set(SAUCER_EMBED_FRONTEND ON)
set(SAUCER_FRONTEND_DIR "${CMAKE_SOURCE_DIR}/source/front-end")
set(saucer_serializer "Rflpp")  # opcional

# -----------------------------------------------------
# Dependencias vía CPM
# -----------------------------------------------------
include(cmake/CPM.cmake)

CPMAddPackage(
  NAME           saucer
  VERSION        6.0.1
  GIT_REPOSITORY "https://github.com/saucer/saucer"
)

FetchContent_MakeAvailable(saucer)

# -----------------------------------------------------
# Ejecutable principal
# -----------------------------------------------------
add_executable(${PROJECT_NAME}
    source/src/main.cc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    saucer::saucer
)
