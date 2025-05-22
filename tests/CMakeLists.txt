include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(StudentasTest studentas_test.cpp)
add_executable(VektoriausTest vector_test.cpp)
target_include_directories(StudentasTest PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(VektoriausTest PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(StudentasTest
    gtest
    gtest_main
)
target_link_libraries(VektoriausTest
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(StudentasTest)
gtest_discover_tests(VektoriausTest)