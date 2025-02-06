# TIME FOR A MODULE.
# Code gets to be sprawling and becomes a mess in a flat structre.

set(TARGET_NAME connect4)

# Note: Now we're making a Library instead of an executable.
# We'll then link our test and run executables to it
add_library(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE
    Connect4.cpp
)

# Time for our first use of the PUBLIC keyword!
# When something includes Connect4 I want to be lazy.
# I want to just `#include <Connect4.h>`
# I hate having to do `#include <Path/To/Connect4.h>
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# The above expands to say:
# When my target goes to include something, also look in my current source directory (./connect4)
# Obviously that's a little silly -- Connect4.cpp will already compile fine without that.
# PUBLIC is the useful part here. It makes it so that anyone who links against us ALSO gets our current directory on their include