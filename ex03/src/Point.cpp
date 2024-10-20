/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:36:59 by josfelip          #+#    #+#             */
/*   Updated: 2024/10/19 23:27:57 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const& src) {
	*this = src;
}

Point::~Point(void) {}

Point&	Point::operator=(Point const& rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

Fixed const&	Point::getX(void) const {
	return _x;
}

Fixed const&	Point::getY(void) const {
	return _y;
}