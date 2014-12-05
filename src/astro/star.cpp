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

    math::Point<F_TYPE> Star::getPosition(void) const
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
