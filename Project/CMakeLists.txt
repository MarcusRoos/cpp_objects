# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${SOURCES} src/Management.cpp include/Management.h src/Song.cpp include/Song.h src/Length.cpp include/Length.h src/Album.cpp include/Album.h src/Jukebox.cpp include/Jukebox.h src/Menu.cpp include/Menu.h src/MenuItem.cpp include/MenuItem.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/ ../_Resources/_libs/)