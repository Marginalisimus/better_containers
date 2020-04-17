cmake_minimum_required(VERSION 3.13)
project(better_containers
	VERSION 0.1.0
	LANGUAGES CXX
)

# CMake tools setup ====================================================================================================
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../tools/cmake-scripts/cmake")
include(scripts)

# Project ==============================================================================================================
set(library ${CMAKE_PROJECT_NAME})
set(namespace ${CMAKE_PROJECT_NAME})

# Dependencies
# find_package(...)

# Sources
file(GLOB_RECURSE library_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
	*.hpp
	*.cpp
)

# Target
add_library(${library} INTERFACE)
foreach(source ${library_sources})
	target_sources(${library} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${source}>)
	target_sources(${library} INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include/${source}>)
endforeach()
target_compile_features(${library} INTERFACE cxx_std_17)
target_include_directories(${library}
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:include>
)
add_library(${namespace}::${library} ALIAS ${library})

# Installation
install_targets(${library})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DESTINATION include
	COMPONENT Devel
)

# Generate configuration files and install the package
configure_and_install(${CMAKE_SCRIPTS_ROOT}/simple-config.cmake.in ${namespace} SameMajorVersion)
