cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Variables
set(PROJECT_NAME "BOILERPLATE")

# Set project name and version
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug
		CACHE STRING
			"Choose the type of build (Debug or Release"
			FORCE
		)
endif()

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

if(NOT USE_INSTALL_RESOURCE_PATH)
	set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/resources/")
else()
	set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/resources/")
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

# Find SFML shared libraries
find_package(SFML 2.5
	COMPONENTS
		system window graphics network audio REQUIRED
	)

# Compile executable
add_executable(
		${PROJECT_NAME}
		source/main.cpp
		source/Entity.cpp
)

# Set include directory search paths
target_include_directories(${PROJECT_NAME}
	PRIVATE
	"${PROJECT_BINARY_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Set executable RPATH
set_target_properties(${PROJECT_NAME}
		PROPERTIES
		INSTALL_RPATH
		"${CMAKE_INSTALL_PREFIX}/lib"
)

# Link executable to require SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics)

# Set executable install location
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
		DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
