#include "test_matrix.hpp"

TEST(TestLibrary, TestTwoDimensionalMatrix) {
	enum: std::size_t {Dimensions = 2};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
