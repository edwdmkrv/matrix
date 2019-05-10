#include "test_matrix.hpp"

TEST(TestLibrary, TestOneHundredDimensionalMatrix) {
	enum: std::size_t {Dimensions = 100};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
