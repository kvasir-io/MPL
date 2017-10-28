//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include <tuple>
#include "zip_with.hpp"
#include "../sequence/at.hpp"
#include "../functional/flow.hpp"
#include "../functional/bind.hpp"
#include "make_sequence.hpp"

namespace kvasir {
	namespace mpl {
		template<typename F, typename C = listify>
		struct index_if{
			template<typename...Ts>
			using f = typename zip_fixed<if_<at<uint_<0>,F>,at<uint_<1>,cfe<list>>,always<list<>>>, 
				call<make_int_sequence<>,uint_<sizeof...(Ts)>>, join<C>>::template f<Ts...>;
		};
	} // namespace mpl
} // namespace kvasir