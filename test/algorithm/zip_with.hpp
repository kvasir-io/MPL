//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/zip_with.hpp>

namespace {
	namespace mpl  = kvasir::mpl;
	using zip_a        = mpl::list<void, char, short, int>;
	using zip_b        = mpl::list<int, void, char, short>;
	using zip_shoud_be = mpl::list<mpl::list<void, int>, mpl::list<char, void>, mpl::list<short,
	                                                                                    char>,
	                           mpl::list<int, short>>;
	static_assert(std::is_same<mpl::zip_with<mpl::list, zip_a, zip_b>, zip_shoud_be>::value, "");
	static_assert(std::is_same<mpl::c::call<mpl::c::zip_with<mpl::lambda<mpl::list>>, zip_a, zip_b>,
	                           zip_shoud_be>::value,
	              "");
}
