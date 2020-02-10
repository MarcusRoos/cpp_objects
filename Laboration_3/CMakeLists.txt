# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_3 ${SOURCES} src/Address.cpp include/Address.h src/Names.cpp include/Names.h src/Person.cpp include/Person.h src/Management.cpp include/Management.h src/PersonList.cpp include/PersonList.h src/UserInterface.cpp include/UserInterface.h src/ClientProgram.cpp)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_3 PRIVATE include/ ../_Resources/_libs/)