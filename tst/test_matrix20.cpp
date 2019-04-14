#include "test_matrix.hpp"

TEST(TestLibrary, TestTwentyDimensionalMatrix) {
	enum: std::size_t {Dimensions = 20};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
