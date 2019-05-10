cmake_minimum_required (VERSION 3.12)

# Project stuff
project (matrix_lib
	VERSION 0.0.${TRAVIS_BUILD_NUMBER}
	DESCRIPTION "Homework 6 sparse matrix implementation library"
	HOMEPAGE_URL "https://github.com/edwdmkrv/matrix/tree/master/lib"
	LANGUAGES CXX
)

# Library stuff
add_library (lib INTERFACE)

# Automatically added to the compile options for the targets linked against the library
set_property (TARGET lib APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
	"${CMAKE_BINARY_DIR}"
	"${CMAKE_SOURCE_DIR}/lib"
)
