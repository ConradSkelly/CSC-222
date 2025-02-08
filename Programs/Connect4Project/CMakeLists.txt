# You always see this as a first line.
# No one actually keeps track of what minimum version of CMake they need,
# but check here for what features get added if you're using something new.
# https://cmake.org/cmake/help/latest/release/index.html
cmake_minimum_required(VERSION 3.16)

# Here we're setting a variable to use later. Then, you can copy-paste much of this and just swap the variable.
# PROJ_NAME is not special, you could replace every instance of ${PROJ_NAME} with Connect4
set(PROJ_NAME Connect4)

# Some variables are special and consumed by CMake. Here we're setting language versions.
# A good IDE will have a list of these available for auto-complete when you type set(CMAKE_
# The online listing is available here:
# https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Tell CMake we're starting a project with the name Connect4, and we intend to use these language(s)
# You may see this line without "LANGUAGES" typed out. It's optional. https://cmake.org/cmake/help/latest/command/project.html
project(${PROJ_NAME} LANGUAGES CXX)

# Now, we define what we want our top-level executable to be named.
# I often use a seperate name here. We can just use PROJ_NAME though.
# To show that these are technically different variables, I'm going to
# just copy PROJ_NAME in to a new TARGET_NAME variable
set(TARGET_NAME ${PROJ_NAME})

add_executable(${TARGET_NAME})

# Executables and Libraries are targets.
# After defining one of these, you must provide the list of sources that go in to making it.
# The PRIVATE here relates to scope.
# It might be a bit early to worry about the nuance here. As a rule of thumb, just keep this PRIVATE.
# If you find yourself needing to pass along dependencies, you can make it PUBLIC.
target_sources(${TARGET_NAME} PRIVATE
    runConnect4.cpp
)

# Note: We removed Connect4.cpp from the above line!
# Now we just let the connect4 library handle its own sources, and then we'll link against it.
# This way, we just have it as a dependency.
target_link_libraries(${TARGET_NAME} PRIVATE
    connect4
)

# Print-style debugging; it can be done for CMAKE too!
# This is useful because CMake "just knows" things sometimes. If you need to set something new, you'll often have to override it.
# https://cmake.org/cmake/help/latest/command/message.html
message(STATUS "Your compiler is: ${CMAKE_CXX_COMPILER}")
message(STATUS "Your RELEASE compile flags are: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Your DEBUG compile flags are: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "You are currently building for: ${CMAKE_BUILD_TYPE}")

# Add our new module to this build
add_subdirectory(connect4)

# Now let's go ahead and add our test binary as well.
# We need to do the following:
# 1. Add a new target for it
# 2. Make doctest.h include-able for it
# 3. Link against connect4, just like our main does
# Out of convention, I'm going to name this binary `test_Connect4`
set(TEST_TARGET_NAME test_${TARGET_NAME})
add_executable(${TEST_TARGET_NAME}
    TestConnect4.cpp # Note: I was lazy this time. I usually do a separate target_sources() call. This is shorthand.
)
target_link_libraries(${TEST_TARGET_NAME} PRIVATE
    connect4
)
target_include_directories(${TEST_TARGET_NAME} PRIVATE
    external/doctest
)