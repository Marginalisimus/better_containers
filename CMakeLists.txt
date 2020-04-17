cmake_minimum_required(VERSION 3.13)
project(better_containers)

# CMake tools setup ====================================================================================================
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake-scripts/cmake")
include(scripts)

# Package manager ------------------------------------------------------------------------------------------------------
conan_init(cmake)

# Tooling --------------------------------------------------------------------------------------------------------------
# enable static analysis
#enable_clang_tidy()
#enable_iwyu()

# Project ==============================================================================================================
# Compiler settings
set_warnings(TREAT_AS_ERRORS)

# Add project code
add_subdirectory(src)

# Add using examples
add_subdirectory(examples)

# Add unit tests
enable_testing()
add_subdirectory(tests)
