# check if conan installed a test framework
conan_check_testing(gtest)

# unit tests
file(GLOB_RECURSE sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
	*.hpp
	*.cpp
)

add_executable(tests)
target_sources(tests PRIVATE ${sources})

target_link_libraries(tests
    PRIVATE
        better_containers::better_containers
        CONAN_PKG::gtest
)

include(GoogleTest)
gtest_discover_tests(tests)