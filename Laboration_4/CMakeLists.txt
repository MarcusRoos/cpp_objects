# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_4 ${SOURCES} src/ArraySort.cpp include/ArraySort.h src/RandomGenerator.cpp src/RandomGenerator.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_4 PRIVATE include/ ../_Resources/_libs/)