/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:31:24 by josfelip          #+#    #+#             */
/*   Updated: 2024/10/21 22:36:02 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {

public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const& src);
	~Point(void);

	Point&	operator=(Point const& rhs);

	Fixed const&	getX(void) const;
	Fixed const&	getY(void) const;

private:
	Fixed	_x;
	Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
