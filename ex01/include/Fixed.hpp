/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:27:36 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/10/16 13:25:06 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

public:
	Fixed(void); //Default constructor
	Fixed(int const num); //Int constructor
	Fixed(float const num); //Float constructor
	Fixed(Fixed const& src); //Copy constructor - creates new instance
	~Fixed(void); //Destructor

	Fixed&	operator=(Fixed const& rhs); //Copy assignment - updates current instance

	//Getters and setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	//Conversion functions
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_rawValue;
	static const int	_FRACTIONAL_BITS = 8;
	static const int	_SCALE = 256; // 2^8
};

std::ostream&	operator<<(std::ostream& o, Fixed const& rhs);

#endif
