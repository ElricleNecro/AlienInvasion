#include "profile/uniformsphere.hpp"
#include "astro/star.hpp"

namespace profile
{
	UniformSphere::UniformSphere(F_TYPE radius, long seed): Generator(seed), _radius2(radius*radius)
	{
	}

	UniformSphere::~UniformSphere(void)
	{
	}

	void UniformSphere::generate(long N)
	{
		//
	}


	F_TYPE UniformSphere::profile(F_TYPE x, F_TYPE y, F_TYPE z)
	{
		if( x*x + y*y + z*z < this->_radius2 )
			return 1.;
		return 0.;
	}
} /* profile */
