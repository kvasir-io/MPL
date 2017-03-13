//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "compatability.hpp"
#include <limits>

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				constexpr bool always_true(const std::size_t in) {
					return in < std::numeric_limits<std::size_t>::max();
				}
				template<typename T, bool I>
				struct dependant_call {};

				template<typename T>
				struct dependant_call<T, true> : T {
				};
			}
		}
	}
}

#if defined(KVASIR_MSVC_2017) || defined(KVASIR_MSVC_2015) || defined(KVASIR_MSVC_2013) || defined(KVASIR_CLANG_36) || defined(KVASIR_CLANG_37)

#define KVASIR_D_CALL(Continuation,Pack)  typename ::kvasir::mpl::c::detail::dependant_call<Continuation,::kvasir::mpl::c::detail::always_true(sizeof...(Pack))>::template f

#else

#define KVASIR_D_CALL(T,Pack)  typename T::template f

#endif