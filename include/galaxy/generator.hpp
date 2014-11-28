#ifndef GENERATOR_HPP_BHKGEQLN
#define GENERATOR_HPP_BHKGEQLN

#include "config.hpp"

namespace galaxy
{
	class Generator
	{
		public:
			Generator(long seed=-32) noexcept;
			virtual ~Generator(void) noexcept;

			virtual F_TYPE profile(F_TYPE x, F_TYPE y, F_TYPE z) = 0;

			void generate(long N);

		private:
			long _seed;
	};
} /* galaxy */

#endif /* end of include guard: GENERATOR_HPP_BHKGEQLN */
