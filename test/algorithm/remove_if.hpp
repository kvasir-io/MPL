//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/algorithm/remove_if.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>
namespace remove_if_test {
	using namespace kvasir::mpl;
	template <typename T>
	using less_than_5 = bool_<(T::value < 5)>;

	struct less_than_5_c {
		template <typename T>
		using f = less_than_5<T>;
	};

	static_assert(
	        std::is_same<eager::remove_if<list<int_<1>, int_<2>, int_<7>, int_<8>>, less_than_5>,
	                     list<int_<7>, int_<8>>>::value,
	        "");

	template <typename... Ts>
	using test = call<remove_if<less_than_5_c>, Ts...>;
	static_assert(
	        std::is_same<test<int_<1>, int_<2>, int_<7>, int_<8>>, list<int_<7>, int_<8>>>::value,
	        "");
} // namespace remove_if_test