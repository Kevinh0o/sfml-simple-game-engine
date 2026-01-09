cmake_minimum_required(VERSION 3.28)

project(ecs-game-engine
    VERSION 0.1.0
    LANGUAGES CXX
)

# ----------------------------------
# Global settings
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ----------------------------------
# Fetch SFML 2.6.1
# ----------------------------------
include(FetchContent)

# Disable unused SFML modules (faster build)
set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)
set(SFML_BUILD_EXAMPLES FALSE)
set(SFML_BUILD_DOC FALSE)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

message(STATUS "Using SFML version: ${SFML_VERSION}")

# ----------------------------------
# Engine static library
# ----------------------------------
add_library(engine STATIC
    src/components.cpp
    src/entity.cpp
    src/entityManager.cpp
    src/game.cpp
    src/input.cpp
    src/movement.cpp
    src/multimedia.cpp
    src/random.cpp
    src/timer.cpp
    src/vec2d.cpp
)

target_include_directories(engine
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(engine
    PUBLIC
        sfml-system
        sfml-window
        sfml-graphics
)

# ----------------------------------
# Game executable
# ----------------------------------
add_executable(main
    src/main.cpp
)

target_link_libraries(main
    PRIVATE
        engine
)

# ----------------------------------
# Visual Studio convenience
# ----------------------------------
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT main
)
