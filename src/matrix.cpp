#include <cstdlib>

#include <iostream>

#include "lib.hpp"

enum: std::size_t {Dimensions = 2};

template <typename Type, Type Default>
void fill(usr::Matrix<Type, Default, Dimensions> &matrix) {
	static_assert (Dimensions == 2,
		"Function fill() is prepared to handle 2-dimensional matrices only"
	);

	enum: std::size_t {first = 0, last = 9};

	for (std::size_t idx{first}; idx <= last; idx++) {
		auto const &ridx{last - idx};
		auto &&submatrix{matrix[idx]};

		submatrix[idx] = idx;
		submatrix[ridx] = ridx;
	}
}

template <typename Type, Type Default>
void print(usr::Matrix<Type, Default, Dimensions> const &matrix) {
	static_assert (Dimensions == 2,
		"Function print() is prepared to handle 2-dimensional matrices only"
	);

	enum: std::size_t {first = 1, last = 8};

	for (std::size_t y{first}; y <= last; y++) {
		for (std::size_t x{first}; x <= last; x++) {
			std::cout << matrix[y][x] << ' ';
		}

		std::cout << '\n';
	}

	std::cout << std::endl;

	std::cout << "size = " << matrix.size() << '\n' << std::endl;

	for (auto const &[x1, x0, value]: matrix) {
		std::cout << '[' << x1 << "][" << x0 << "] = " << value << '\n';
	}

	std::cout.flush();
}

int main() try {
	using Type = std::size_t;

	enum: Type {Default = 0};

	usr::Matrix<Type, Default, Dimensions> matrix;

	fill(matrix);
	print(matrix);

	return EXIT_SUCCESS;
} catch (std::exception const &e) {
	std::cerr << "Error: " << e.what() << std::endl;
	return EXIT_FAILURE;
} catch (...) {
	std::cerr << "Error: " << "unidentified exception" << std::endl;
	return EXIT_FAILURE;
}
