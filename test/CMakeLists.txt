file(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_executable(mars-test ${all_files})
target_link_libraries(mars-test mars gtest gtest_main pthread)
