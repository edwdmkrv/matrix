#include "test_matrix.hpp"

TEST(TestLibrary, TestTwoHundredDimensionalMatrix) {
	enum: std::size_t {Dimensions = 200};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
