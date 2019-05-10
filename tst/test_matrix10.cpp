#include "test_matrix.hpp"

TEST(TestLibrary, TestTenDimensionalMatrix) {
	enum: std::size_t {Dimensions = 10};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
