# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_5 ${SOURCES} src/Address.cpp include/Address.h src/Names.cpp include/Names.h src/Person.cpp include/Person.h src/HousingQ.cpp include/HousingQ.h src/queue.cpp include/queue.h src/Management.cpp include/Management.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_5 PRIVATE include/ ../_Resources/_libs/)