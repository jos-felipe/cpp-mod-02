/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:26:59 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/10/19 21:54:40 by josfelip         ###   ########.fr       */
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

// Arithmetic operators
Fixed	Fixed::operator+(Fixed const& rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator-(Fixed const& rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed	Fixed::operator*(Fixed const& rhs) const {
	Fixed result;
	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _FRACTIONAL_BITS);
	return result;
}

Fixed	Fixed::operator/(Fixed const& rhs) const {
	Fixed result;
	result.setRawBits((this->getRawBits() << _FRACTIONAL_BITS) / rhs.getRawBits());
	return result;
}

// Increment and decrement operators
Fixed&	Fixed::operator++(void) {
	this->_rawValue++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	this->_rawValue--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Comparison operators
bool	Fixed::operator>(Fixed const& rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const& rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const& rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const& rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const& rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const& rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

//=================================STREAM OPERATOR============================//

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

//=================================STATIC FUNCTIONS===========================//

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b) {
	return (a < b) ? a : b;
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b) {
	return (a > b) ? a : b;
}


