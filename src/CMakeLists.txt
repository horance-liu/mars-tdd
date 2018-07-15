FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.c++
*.c
*.C)

add_library(mars STATIC ${all_files})
install(TARGETS mars ARCHIVE DESTINATION lib)
