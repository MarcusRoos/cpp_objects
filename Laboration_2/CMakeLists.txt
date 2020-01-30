#Add source directory

# this cant be used if you have multiple main
# aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_2-namesTest src/namesTest.cpp src/Names.cpp)
add_executable(${PROJECT_NAME}-Laboration_2-addressTest src/addressTest.cpp src/Address.cpp)
add_executable(${PROJECT_NAME}-Laboration_2-personTest src/personTest.cpp src/Person.cpp src/Names.cpp src/Address.cpp)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_2-namesTest PRIVATE include/ ../_Resources/_libs/)
target_include_directories(${PROJECT_NAME}-Laboration_2-addressTest PRIVATE include/ ../_Resources/_libs/)
target_include_directories(${PROJECT_NAME}-Laboration_2-personTest PRIVATE include/ ../_Resources/_libs/)