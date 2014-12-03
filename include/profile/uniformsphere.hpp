#ifndef UNIFORMSPHERE_HPP_IUGZVOTP
#define UNIFORMSPHERE_HPP_IUGZVOTP

#include "profile/generator.hpp"

#include "config.hpp"

namespace profile
{
	class UniformSphere: public Generator
	{
		public:
			UniformSphere(F_TYPE radius, long seed=-32);

			virtual ~UniformSphere(void);

			F_TYPE profile(F_TYPE x, F_TYPE y, F_TYPE z);

		private:
			F_TYPE _radius2;
	};
} /* profile */

#endif /* end of include guard: UNIFORMSPHERE_HPP_IUGZVOTP */

