//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/fold_right.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/functions/arithmetic/plus.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	namespace mpl = kvasir::mpl;
	using mpl::uint_;

	template <typename T1, typename T2>
	using add = uint_<(T1::value + T2::value)>;

	template <typename T, typename U>
	struct push;
	template <typename... Ts, typename U>
	struct push<mpl::list<Ts...>, U> {
		using type = mpl::list<U, Ts...>;
	};

	static_assert(
	        std::is_same<mpl::eager::fold_right<mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>,
	                                            uint_<0>, add>,
	                     uint_<10>>::value,
	        "");

	static_assert(std::is_same<mpl::eager::fold_right<mpl::list<uint_<1>, uint_<2>>, mpl::list<>,
	                                                  mpl::cfl<push>::template f>,
	                           mpl::list<uint_<1>, uint_<2>>>::value,
	              "");
	static_assert(std::is_same<mpl::eager::fold_right<mpl::list<uint_<1>, uint_<2>, uint_<3>>,
	                                                  mpl::list<>, mpl::cfl<push>::template f>,
	                           mpl::list<uint_<1>, uint_<2>, uint_<3>>>::value,
	              "");
	static_assert(
	        std::is_same<mpl::eager::fold_right<mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>,
	                                            mpl::list<>, mpl::cfl<push>::template f>,
	                     mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>>::value,
	        "");
	static_assert(std::is_same<mpl::eager::fold_right<
	                                   mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>>,
	                                   mpl::list<>, mpl::cfl<push>::template f>,
	                           mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>>>::value,
	              "");
	static_assert(
	        std::is_same<
	                mpl::eager::fold_right<
	                        mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>, uint_<6>>,
	                        mpl::list<>, mpl::cfl<push>::template f>,
	                mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>, uint_<6>>>::value,
	        "");
	static_assert(
	        std::is_same<mpl::eager::fold_right<mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>,
	                                                      uint_<5>, uint_<6>, uint_<7>>,
	                                            mpl::list<>, mpl::cfl<push>::template f>,
	                     mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>, uint_<6>,
	                               uint_<7>>>::value,
	        "");

	template <typename C, typename T>
	struct fold_right_foo {
		template <typename... Ts>
		using f = mpl::call<C, Ts..., T>;
	};

	static_assert(std::is_same<mpl::call<mpl::call<mpl::fold_right<mpl::cfe<fold_right_foo>>,
	                                               mpl::listify, char, short, int>,
	                                     void>,
	                           mpl::list<void, char, short, int>>::value,
	              "");

	template <typename T>
	struct fold_right_cont_test {
		template <typename... Ts>
		using f = typename mpl::dcall<mpl::fold_right<mpl::cfe<add>>,
		                              sizeof...(Ts)>::template f<uint_<1>, Ts...>;
	};
} // namespace
