cmake_minimum_required(VERSION 3.28)
project(sfml-simple-game-engine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SFML)

# --------------------
# Engine library
# --------------------
add_library(engine
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

target_compile_features(engine PUBLIC cxx_std_17)

target_include_directories(engine
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(engine
    PUBLIC
        SFML::System
        SFML::Window
        SFML::Graphics
)

# --------------------
# Game executable
# --------------------
add_executable(main
    src/main.cpp
)

target_link_libraries(main PRIVATE engine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
             PROPERTY VS_STARTUP_PROJECT main)
