#ifndef __TEST_MATRIX_INCLUDED
#define __TEST_MATRIX_INCLUDED

#include "lib.hpp"

#include <gtest/gtest.h>

#include <limits>
#include <tuple>

using Type = int;

enum: Type {Default = 1};
enum: std::size_t {items = 1'000'000};

static inline constexpr Type nonDefault(Type const &value) {
	return
		value != Default ?
			value :
			value == std::numeric_limits<Type>::max() ?
				value - 1 :
				value + 1;
}

template <std::size_t N>
inline auto dereference(usr::Matrix<Type, Default, N> &m, std::size_t const x);

template <>
inline auto dereference<1>(usr::Matrix<Type, Default, 1> &m, std::size_t const x) {
	return m[x];
}

template <>
inline auto dereference<2>(usr::Matrix<Type, Default, 2> &m, std::size_t const x) {
	return m[x][x + 1];
}

template <>
inline auto dereference<5>(usr::Matrix<Type, Default, 5> &m, std::size_t const x) {
	return m[x][x + 1][x + 2][x + 3][x + 4];
}

template <>
inline auto dereference<10>(usr::Matrix<Type, Default, 10> &m, std::size_t const x) {
	return m[x][x + 1][x + 2][x + 3][x + 4][x + 5][x + 6][x + 7][x + 8][x + 9];
}

template <>
inline auto dereference<20>(usr::Matrix<Type, Default, 20> &m, std::size_t const x) {
	return m
		[x      ][x +   1][x +   2][x +   3][x +   4][x +   5][x +   6][x +   7][x +   8][x +   9]
		[x +  10][x +  11][x +  12][x +  13][x +  14][x +  15][x +  16][x +  17][x +  18][x +  19];
}

template <>
inline auto dereference<50>(usr::Matrix<Type, Default, 50> &m, std::size_t const x) {
	return m
		[x      ][x +   1][x +   2][x +   3][x +   4][x +   5][x +   6][x +   7][x +   8][x +   9]
		[x +  10][x +  11][x +  12][x +  13][x +  14][x +  15][x +  16][x +  17][x +  18][x +  19]
		[x +  20][x +  21][x +  22][x +  23][x +  24][x +  25][x +  26][x +  27][x +  28][x +  29]
		[x +  30][x +  31][x +  32][x +  33][x +  34][x +  35][x +  36][x +  37][x +  38][x +  39]
		[x +  40][x +  41][x +  42][x +  43][x +  44][x +  45][x +  46][x +  47][x +  48][x +  49];
}

template <>
inline auto dereference<100>(usr::Matrix<Type, Default, 100> &m, std::size_t const x) {
	return m
		[x      ][x +   1][x +   2][x +   3][x +   4][x +   5][x +   6][x +   7][x +   8][x +   9]
		[x +  10][x +  11][x +  12][x +  13][x +  14][x +  15][x +  16][x +  17][x +  18][x +  19]
		[x +  20][x +  21][x +  22][x +  23][x +  24][x +  25][x +  26][x +  27][x +  28][x +  29]
		[x +  30][x +  31][x +  32][x +  33][x +  34][x +  35][x +  36][x +  37][x +  38][x +  39]
		[x +  40][x +  41][x +  42][x +  43][x +  44][x +  45][x +  46][x +  47][x +  48][x +  49]
		[x +  50][x +  51][x +  52][x +  53][x +  54][x +  55][x +  56][x +  57][x +  58][x +  59]
		[x +  60][x +  61][x +  62][x +  63][x +  64][x +  65][x +  66][x +  67][x +  68][x +  69]
		[x +  70][x +  71][x +  72][x +  73][x +  74][x +  75][x +  76][x +  77][x +  78][x +  79]
		[x +  80][x +  81][x +  82][x +  83][x +  84][x +  85][x +  86][x +  87][x +  88][x +  89]
		[x +  90][x +  91][x +  92][x +  93][x +  94][x +  95][x +  96][x +  97][x +  98][x +  99];
}

template <>
inline auto dereference<200>(usr::Matrix<Type, Default, 200> &m, std::size_t const x) {
	return m
		[x      ][x +   1][x +   2][x +   3][x +   4][x +   5][x +   6][x +   7][x +   8][x +   9]
		[x +  10][x +  11][x +  12][x +  13][x +  14][x +  15][x +  16][x +  17][x +  18][x +  19]
		[x +  20][x +  21][x +  22][x +  23][x +  24][x +  25][x +  26][x +  27][x +  28][x +  29]
		[x +  30][x +  31][x +  32][x +  33][x +  34][x +  35][x +  36][x +  37][x +  38][x +  39]
		[x +  40][x +  41][x +  42][x +  43][x +  44][x +  45][x +  46][x +  47][x +  48][x +  49]
		[x +  50][x +  51][x +  52][x +  53][x +  54][x +  55][x +  56][x +  57][x +  58][x +  59]
		[x +  60][x +  61][x +  62][x +  63][x +  64][x +  65][x +  66][x +  67][x +  68][x +  69]
		[x +  70][x +  71][x +  72][x +  73][x +  74][x +  75][x +  76][x +  77][x +  78][x +  79]
		[x +  80][x +  81][x +  82][x +  83][x +  84][x +  85][x +  86][x +  87][x +  88][x +  89]
		[x +  90][x +  91][x +  92][x +  93][x +  94][x +  95][x +  96][x +  97][x +  98][x +  99]
		[x + 100][x + 101][x + 102][x + 103][x + 104][x + 105][x + 106][x + 107][x + 108][x + 109]
		[x + 110][x + 111][x + 112][x + 113][x + 114][x + 115][x + 116][x + 117][x + 118][x + 119]
		[x + 120][x + 121][x + 122][x + 123][x + 124][x + 125][x + 126][x + 127][x + 128][x + 129]
		[x + 130][x + 131][x + 132][x + 133][x + 134][x + 135][x + 136][x + 137][x + 138][x + 139]
		[x + 140][x + 141][x + 142][x + 143][x + 144][x + 145][x + 146][x + 147][x + 148][x + 149]
		[x + 150][x + 151][x + 152][x + 153][x + 154][x + 155][x + 156][x + 157][x + 158][x + 159]
		[x + 160][x + 161][x + 162][x + 163][x + 164][x + 165][x + 166][x + 167][x + 168][x + 169]
		[x + 170][x + 171][x + 172][x + 173][x + 174][x + 175][x + 176][x + 177][x + 178][x + 179]
		[x + 180][x + 181][x + 182][x + 183][x + 184][x + 185][x + 186][x + 187][x + 188][x + 189]
		[x + 190][x + 191][x + 192][x + 193][x + 194][x + 195][x + 196][x + 197][x + 198][x + 199];
}

template <std::size_t Dimensions>
void test(usr::Matrix<Type, Default, Dimensions> &&matrix) {
	EXPECT_EQ(matrix.size(), 0);
	EXPECT_EQ(dereference(matrix, 0), Default);

	dereference(matrix, 0) = nonDefault(Default);
	EXPECT_EQ(matrix.size(), 1);

	dereference(matrix, 0) = Default;
	EXPECT_EQ(matrix.size(), 0);

	dereference(matrix, 0) = dereference(matrix, 0);
	EXPECT_EQ(matrix.size(), 0);

	dereference(matrix, 0) = nonDefault(dereference(matrix, 0) + 1);
	EXPECT_EQ(matrix.size(), 1);

	dereference(matrix, 0) = dereference(matrix, 0);
	EXPECT_EQ(matrix.size(), 1);

	dereference(matrix, 0) = dereference(matrix, std::numeric_limits<std::size_t>::max() - Dimensions + 1);
	EXPECT_EQ(matrix.size(), 0);

	for (std::size_t x{}; x < items; x++) {
		dereference(matrix, x) = nonDefault(x + 1);
	}

	EXPECT_EQ(matrix.size(), items);

	std::size_t cnt{};

	for (auto const &tuple: matrix) {
		ASSERT_EQ(std::get<0>(tuple), cnt);
		ASSERT_EQ(std::get<std::tuple_size<typename std::decay<decltype(tuple)>::type>::value - 1>(tuple), nonDefault(cnt + 1));
		cnt++;
	}

	EXPECT_EQ(cnt, items);

	while (cnt) {
		auto const &begin{std::begin(matrix)};

		ASSERT_NE(begin, std::end(matrix));

		auto const &tuple{*begin};

		dereference(matrix, std::get<0>(tuple)) = Default;
		ASSERT_EQ(matrix.size(), --cnt);
	}

	EXPECT_EQ(std::begin(matrix), std::end(matrix));
	EXPECT_EQ(matrix.size(), cnt);

	((dereference(matrix, 100) = nonDefault(314)) = nonDefault(0)) = nonDefault(217);

	EXPECT_EQ(matrix.size(), 1);
	EXPECT_EQ(dereference(matrix, 100), nonDefault(217));
}

#endif
