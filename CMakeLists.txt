cmake_minimum_required(VERSION 3.29)

# Print build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# TODO: Check if needed for macOS
#set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0" CACHE STRING "Minimum OS X deployment version")

###########################################################
# Set options for libs
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW) # Needed to set options of subprojects inside parent project

###########################################################
# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false) # Don't use GNU++

###########################################################
# Our project
project("ReedSolomon"
	VERSION 1.0.0
	DESCRIPTION "ReedSolomon error correction library"
	LANGUAGES CXX
)

# Main library
add_library("${PROJECT_NAME}"
	include/GaloisField.hpp
	include/Polynomial.hpp
	include/Utils.hpp
	include/ReedSolomonImpl.hpp
	include/ReedSolomon.hpp
	include/DataChunker.hpp
	src/GaloisField.cpp
	src/Polynomial.cpp
	src/ReedSolomonImpl.cpp
)

# The projects include directories
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

###########################################################
# Project versioning
configure_file(ReedSolomonVersion.hpp.cmake "${CMAKE_CURRENT_SOURCE_DIR}/include/ReedSolomonVersion.hpp")

###########################################################
# Examples
add_subdirectory("examples/simple example")
add_subdirectory("examples/chunk example")

#############################################################
# Optimization
target_compile_options("${PROJECT_NAME}" PRIVATE "-O3")

###########################################################
# Add as many warnings as possible
if (WIN32)
	if (MSVC)
		target_compile_options("${PROJECT_NAME}" PRIVATE "/W3")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/WX")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/wd4244")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/wd4267")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/D_CRT_SECURE_NO_WARNINGS")
	endif()
	# Force Win32 to UNICODE
	target_compile_definitions("${PROJECT_NAME}" PRIVATE UNICODE _UNICODE)
else()
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wall")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wextra")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-pedantic")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wmissing-declarations")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wdeprecated")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wshadow")
	#target_compile_options("${PROJECT_NAME}" PRIVATE "-Werror")
	#target_compile_options("${PROJECT_NAME}" PRIVATE "-Wsign-conversion")
endif()
