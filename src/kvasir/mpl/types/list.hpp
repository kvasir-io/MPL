//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				//recursive list, for internal use only
				template<typename Head, typename Tail>
				struct rlist {};
				using rlist_tail_of8 = rlist<list<>, rlist<list<>, rlist<list<>, rlist<list<>, rlist<list<>, rlist<list<>, rlist<list<>, rlist<list<>, void>>>>>>>>;
			}
		}
		template <typename... Ts>
		struct list {};

		template <typename... Ts>
		list<Ts...> make_list(Ts...) {
			return {};
		}
		namespace c {
			struct listify{
				template<typename...Ts>
				using f = list<Ts...>;
			};
		}
	}
}