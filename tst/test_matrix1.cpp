#include "test_matrix.hpp"

TEST(TestLibrary, TestOneDimensionalMatrix) {
	enum: std::size_t {Dimensions = 1};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
