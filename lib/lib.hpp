#ifndef __LIB_INCLUDED
#define __LIB_INCLUDED

#include <cstdint>

#include <functional>
#include <memory>
#include <iterator>
#include <array>
#include <map>
#include <tuple>

#include <version.hpp>

/* Version stuff
 */

namespace ver {

static inline std::string full() {
	return PROJECT_VERSION;
}

static inline unsigned major() {
	return PROJECT_VERSION_MAJOR;
}

static inline unsigned minor() {
	return PROJECT_VERSION_MINOR;
}

static inline unsigned patch() {
	return PROJECT_VERSION_PATCH;
}

} // namespace ver

namespace usr {

template <typename X, X D, std::size_t N>
class Matrix {
	static_assert (N > 0,
		"Number of dimensions must be greater than 0"
	);

private:
	using idx_type = std::size_t;
	using key_type = std::array<idx_type, N>;
	using map_type = std::map<key_type, X>;
	using map_const_iterator = typename map_type::const_iterator;

	map_type map;
	X const def;

	template <typename M>
	class IdxBase {
	protected:
		M &matrix;
		std::shared_ptr<key_type> key;

	public:
		IdxBase(M &matrix, std::shared_ptr<key_type> const &key): matrix{matrix}, key{key} {
		}
	};

	template <typename M, std::size_t Y, std::size_t Z = N>
	class Idx: private IdxBase<M> {
		static_assert (Z > 0,
			"Requirement for Idx<M, N>: N > 0"
		);

		static_assert (Y < Z,
			"Requirement for Idx<M, N>: M <= N"
		);

		using IdxBase<M>::key;

	public:
		Idx(Idx<M, Y - 1, Z> const &idxn, idx_type const idx): IdxBase<M>{idxn.matrix, idxn.key} {
			(*key)[Y - 1] = idx;
		}

		Idx<M, Y + 1, Z> operator [](idx_type const idx) {
			return {*this, idx};
		}

		friend class Idx<M, Y + 1, Z>;
	};

	template <typename M, std::size_t Z>
	class Idx<M, 0, Z>: private IdxBase<M> {
	public:
		Idx(M &matrix): IdxBase<M>{matrix, std::shared_ptr<key_type>{new key_type}} {
		}

		friend class Idx<M, 1, Z>;
	};

	template <typename M, std::size_t Z>
	class Idx<M, Z, Z>: private IdxBase<M> {
		using IdxBase<M>::matrix;
		using IdxBase<M>::key;

	public:
		Idx(Idx<M, Z - 1, Z> const &idxn, idx_type const idx): IdxBase<M>{idxn.matrix, idxn.key} {
			(*key)[Z - 1] = idx;
		}

		operator X const &() const {
			auto const it{matrix.map.find(*key)};

			return {it != matrix.map.end() ? it->second : matrix.def};
		}

		Idx &operator =(X const &x) {
			if (x != D) {
				matrix.map[*key] = x;
			} else {
				auto const iter{matrix.map.find(*key)};

				if (iter != matrix.map.end()) {
					matrix.map.erase(iter);
				}
			}

			return *this;
		}

		Idx &operator =(Idx const &idx) {
			return operator =(static_cast<X const &>(idx));
		}
	};

	class ConstIterator {
	private:
		map_const_iterator iterator;

		ConstIterator(map_const_iterator const &iterator) noexcept(noexcept(map_const_iterator{iterator})): iterator{iterator} {
		}

		template <typename Y, std::size_t... I>
		static auto tuple_from_array_executive(Y const &a, X const &x, std::index_sequence<I...>) {
			return std::make_tuple(a[I]..., x);
		}

		template <typename Y, std::size_t M, typename I = std::make_index_sequence<M>>
		static auto tuple_from_array(std::array<Y, M> const &a, X const &x) {
			return tuple_from_array_executive(a, x, I{});
		}

		friend class Matrix;

	public:
		using value_type = typename map_const_iterator::value_type;
		using difference_type = typename map_const_iterator::difference_type;
		using pointer = typename map_const_iterator::pointer;
		using reference = typename map_const_iterator::reference;
		using iterator_category = typename map_const_iterator::iterator_category;

		ConstIterator const &operator ++() noexcept(noexcept(++iterator)) {
			++iterator;
			return *this;
		}

		bool operator !=(ConstIterator const &const_iter) const noexcept {
			return iterator != const_iter.iterator;
		}

		bool operator ==(ConstIterator const &const_iter) const noexcept {
			return !operator !=(const_iter);
		}

		auto operator *() const {
			auto const &tmp{*iterator};

			return tuple_from_array(tmp.first, tmp.second);
		}
	};

public:
	Matrix() noexcept(noexcept(map_type{}) && noexcept(X{})): map{}, def{D} {
	}

	Idx<Matrix<X, D, N>, 1, N> operator [](std::size_t const idx) {
		return {Idx<Matrix<X, D, N>, 0, N>{*this}, idx};
	}

	Idx<Matrix<X, D, N> const, 1, N> operator [](std::size_t const idx) const {
		return {Idx<Matrix<X, D, N> const, 0, N>{*this}, idx};
	}

	typename map_type::size_type size() const noexcept(noexcept(map.size())) {
		return map.size();
	}

	ConstIterator begin() const noexcept(noexcept(std::cbegin(map))) {
		return {std::cbegin(map)};
	}

	ConstIterator end() const noexcept(noexcept(std::cend(map))) {
		return {std::cend(map)};
	}
};

} // namespace usr

#endif
