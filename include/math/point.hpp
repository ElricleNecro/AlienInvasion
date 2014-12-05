#ifndef POINT_HPP_XYZAVKQG
#define POINT_HPP_XYZAVKQG

#include <stdexcept>

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
			Point(T v[4])
			{
				for(int i=0; i < 4; i++)
					this->_pos[i] = v[i];
			}
			Point(std::initializer_list<T> l)
			{
				for(int i=0; i < 4 || i < l.size(); i++)
					this->_pos[i] = l[i];
			}

			Point(Point<T>& point)
			: _pos(
				{
					point._pos[0],
					point._pos[1],
					point._pos[2],
					point._pos[3]
				}
			      )
			{
			}

			Point(void)
			: _pos(
				{
					0.,
					0.,
					0.,
					0.
				}
			)
			{
			}

			virtual ~Point(void)
			{
			}

			T operator[](int i) const
			{
				// check range of values
				if( i < 0 || i >= 4 )
					throw std::out_of_range("Index must be between 0 and 3.");

				// easier this way
				return this->_pos[i];
			}

			T& operator[](int i)
			{
				// check range of values
				if( i < 0 || i >= 4 )
					throw std::out_of_range("Index must be between 0 and 3.");

				// easier this way
				return this->_pos[i];
			}

			Point<T>& operator=(Point<T>& point)
			{
				// copy positions
				for(int i=0; i < 4; i++)
					this->_pos[i] = point[i];
				return *this;
			}

			Point<T>& operator=(std::initializer_list<T>& point)
			{
				// check we are using 4vector
				if(point.size() != 4)
					throw std::length_error(
							"Point length must be 4 for 4vector!"
							);

				// copy positions
				for(int i=0; i < 4; i++)
					this->_pos[i] = point[i];
				return *this;
			}

		private:
			/* data */
			T _pos[4];
	};
} /* math */

#endif /* end of include guard: POINT_HPP_XYZAVKQG */
