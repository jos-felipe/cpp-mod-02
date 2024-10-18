/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:26:59 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/10/16 13:22:13 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

//================================CONSTRUCTORS================================//

Fixed::Fixed(void) : _rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _rawValue(num << _FRACTIONAL_BITS) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num) {
	std::cout << "Float constructor called" << std::endl;
	_rawValue = static_cast<int>(roundf(num * _SCALE));
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

//=================================OPERATORS==================================//

Fixed&			Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawValue = rhs.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}

//==================================GETTERS===================================//

int		Fixed::getRawBits(void) const {
	return _rawValue;
}

//==================================SETTERS===================================//

void	Fixed::setRawBits(int const raw) {
	_rawValue = raw;
}

//=================================MEMBER FUNCTIONS===========================//

int		Fixed::toInt(void) const {
	return (this->getRawBits() >> _FRACTIONAL_BITS);
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->getRawBits()) / _SCALE);
}
