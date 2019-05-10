#include "test_matrix.hpp"

TEST(TestLibrary, TestFiftyDimensionalMatrix) {
	enum: std::size_t {Dimensions = 50};

	test(usr::Matrix<Type, Default, Dimensions>{});
}
