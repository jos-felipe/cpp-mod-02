/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:50:04 by josfelip          #+#    #+#             */
/*   Updated: 2024/10/19 23:50:07 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// Function to calculate the signed area of a triangle
Fixed signedArea(Point const& p1, Point const& p2, Point const& p3) {
    return (p1.getX() * (p2.getY() - p3.getY()) + 
            p2.getX() * (p3.getY() - p1.getY()) + 
            p3.getX() * (p1.getY() - p2.getY())) / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the signed areas
    Fixed area_abc = signedArea(a, b, c);
    Fixed area_pbc = signedArea(point, b, c);
    Fixed area_apc = signedArea(a, point, c);
    Fixed area_abp = signedArea(a, b, point);

    // Check if all areas have the same sign and sum up to the total area
    bool all_positive = (area_abc > 0 && area_pbc > 0 && area_apc > 0 && area_abp > 0);
    bool all_negative = (area_abc < 0 && area_pbc < 0 && area_apc < 0 && area_abp < 0);

    if (all_positive || all_negative) {
        Fixed sum = area_pbc + area_apc + area_abp;
        return sum == area_abc && sum != 0;
    }

    return false;
}
