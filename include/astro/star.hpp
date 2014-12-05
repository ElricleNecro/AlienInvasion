#ifndef STAR_HPP_NASTO4VH
#define STAR_HPP_NASTO4VH

#include <initializer_list>

#include "math/point.hpp"

#include "config.hpp"

namespace astro
{
    class Star
    {
        public:
            Star(void);
            Star(math::Point<F_TYPE> position, F_TYPE mass);
            virtual ~Star(void);

            math::Point<F_TYPE> getPosition(void) const;
            void setPosition(math::Point<F_TYPE> position);
            void setPosition(std::initializer_list<F_TYPE> position);

            F_TYPE getMass(void) const;
            void setMass(F_TYPE mass);

        private:
            math::Point<F_TYPE> _position;
            F_TYPE _mass;
    };
} /* astro */

#endif /* end of include guard: STAR_HPP_NASTO4VH */
