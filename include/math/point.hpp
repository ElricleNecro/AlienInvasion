#ifndef POINT_HPP_XYZAVKQG
#define POINT_HPP_XYZAVKQG

#include <exception>

#include "config.h"

namespace math
{
	template<typename T>
	class Point
	{
		public:
			Point(T x, T y, T z, T w)
			{
				this->_pos[0] = x;
				this->_pos[1] = y;
				this->_pos[2] = z;
				this->_pos[3] = w;
			}
			Point(T v[4]);
			{
				for(int i=0; i < 4; i++)
					this->_pos[i] = v[i];
			}
			Point(std::initializer_list<T> l);
			{
				for(int i=0; i < 4 || i < l.size(); i++)
					this->_pos[i] = l[i];
			}

			virtual ~Point(void)
			{
			}

			T operator[](int i)
			{
				if( i < 0 || i >= 4 )
					throw std::out_of_range("Index must be between 0 and 3.");
				return this->_pos[i];
			}

		private:
			/* data */
			T _pos[4];
	};
} /* math */

#endif /* end of include guard: POINT_HPP_XYZAVKQG */
