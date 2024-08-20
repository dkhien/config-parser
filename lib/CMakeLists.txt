# Define the library
add_library(utils STATIC utils.cpp)

# Add compile options for this library
target_compile_options(utils PRIVATE -Wall -Wextra -Wpedantic)

# Add link options for this library
target_link_options(utils PRIVATE -Wl,--as-needed)
