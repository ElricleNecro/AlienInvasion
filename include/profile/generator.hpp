#ifndef GENERATOR_HPP_BHKGEQLN
#define GENERATOR_HPP_BHKGEQLN

#include "config.hpp"

namespace profile
{
	class Generator
	{
		public:
			Generator(long seed=-32) noexcept;
			virtual ~Generator(void) noexcept;

			virtual F_TYPE profile(F_TYPE x, F_TYPE y, F_TYPE z) = 0;

			virtual void generate(long N) = 0;

		protected:
			long _seed;
	};
} /* profile */

#endif /* end of include guard: GENERATOR_HPP_BHKGEQLN */
