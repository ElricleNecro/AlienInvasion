#include "astro/star.hpp"

namespace astro
{
    Star::Star(void)
    {
    }

    Star::Star(math::Point<F_TYPE> position, F_TYPE mass)
    {
    }

    Star::~Star(void)
    {
    }

    math::Point<F_TYPE>& Star::getPosition(void) const
    {
        return this->_position;
    }
    void Star::setPosition(math::Point<F_TYPE> position)
    {
        this->_position = position;
    }
    void Star::setPosition(std::initializer_list<F_TYPE> position)
    {
        // copy the position of the star
        this->_position = position;
        // this->_position[0] = position[0];
        // this->_position[1] = position[1];
        // this->_position[2] = position[2];
        // this->_position[3] = position[3];
    }

    F_TYPE Star::getMass(void) const
    {
        return this->_mass;
    }
    void Star::setMass(F_TYPE mass)
    {
        this->_mass = mass;
    }
} /* astro */
