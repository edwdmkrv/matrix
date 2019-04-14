cmake_minimum_required (VERSION 3.12)

# Project stuff
project (matrix_tst
	VERSION 0.0.${TRAVIS_BUILD_NUMBER}
	DESCRIPTION "Homework 4 IP-address-like item print implementation tests"
	HOMEPAGE_URL "https://github.com/edwdmkrv/print_ip/tree/master/tst"
	LANGUAGES CXX
)

# Test stuff
add_executable (test_matrix1 test_matrix1.cpp)
add_executable (test_matrix2 test_matrix2.cpp)
add_executable (test_matrix5 test_matrix5.cpp)
add_executable (test_matrix10 test_matrix10.cpp)
add_executable (test_matrix20 test_matrix20.cpp)
add_executable (test_matrix50 test_matrix50.cpp)
add_executable (test_matrix100 test_matrix100.cpp)
add_executable (test_matrix200 test_matrix200.cpp)

set_target_properties (test_matrix1 test_matrix2 test_matrix5 test_matrix10 test_matrix20 test_matrix50 test_matrix100 test_matrix200 PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
	LINK_LIBRARIES "${GTEST_LIBRARY};${GTEST_MAIN_LIBRARY};lib;${CMAKE_THREAD_LIBS_INIT}"
)

add_test (NAME Test-one-dimensional-matrix
	COMMAND test_matrix1
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-two-dimensional-matrix
	COMMAND test_matrix2
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-five-dimensional-matrix
	COMMAND test_matrix5
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-ten-dimensional-matrix
	COMMAND test_matrix10
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-twenty-dimensional-matrix
	COMMAND test_matrix20
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-fifty-dimensional-matrix
	COMMAND test_matrix50
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-one-hundred-dimensional-matrix
	COMMAND test_matrix100
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_test (NAME Test-two-hundred-dimensional-matrix
	COMMAND test_matrix200
	WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

include (CTest)
