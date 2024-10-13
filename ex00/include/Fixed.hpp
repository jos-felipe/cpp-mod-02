/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:27:36 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/10/13 20:27:45 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

public:
	Fixed(void); //Default constructor
	Fixed(Fixed const& src); //Copy constructor - creates new instance
	~Fixed(void); //Destructor

	Fixed&	operator=(Fixed const& rhs); //Copy assignment - updates current instance

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawValue;
	static const int	_FRACTIONAL_BITS = 8;
};

#endif
