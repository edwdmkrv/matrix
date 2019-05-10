#include "test_matrix.hpp"

TEST(TestLibrary, TestFiveDimensionalMatrix) {
	enum: std::size_t {Dimensions = 5};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
