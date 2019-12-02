//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/fold_left.hpp>
#include <kvasir/mpl/functions/arithmetic/plus.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

#include <metacheck/metacheck.hpp>

namespace fold_left {
	namespace mpl = kvasir::mpl;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<
	        mpl::unpack<mpl::push_front<mpl::uint_<0>, mpl::fold_left<mpl::plus<>>>>::template f,
	        mpl::eager::join, mpl::eager::plus, L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, mc::gen::list_of<mc::gen::uint_<>>,
	                 mc::gen::list_of<mc::gen::uint_<>>>;

	template <typename L>
	using ordering = mc::mpl::equal<
	        L, mpl::call<mpl::unpack<mpl::push_front<
	                             mpl::list<>,
	                             mpl::fold_left<mpl::fork<mpl::at1<>, mpl::at0<>,
	                                                      mpl::cfe<mpl::eager::push_back>>>>>,
	                     L>>;

	constexpr auto ordering_test = mc::test<ordering, 20, mc::gen::list_of<mc::gen::anything>>;
} // namespace fold_left

constexpr auto fold_left_section_t =
        mc::section("fold_left", fold_left::distributive_test, fold_left::ordering_test);
extern mc::result *fold_left_section;
