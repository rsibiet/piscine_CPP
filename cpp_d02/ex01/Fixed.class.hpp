/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:19:27 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/31 10:19:29 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H
#include <iostream>
#include <cmath>

class Fixed
{

public:

	Fixed(void);
	Fixed(Fixed const &f);
	Fixed(int const i);
	Fixed(float const fl);
	~Fixed(void);

	Fixed				&operator=(Fixed const & nb);
	void 				setRawBits(int const raw);
	int 				getRawBits(void) const;
	float				toFloat(void) const;
	int					toInt(void) const; 

private:

	int					_fPoint;
	static const int	_nbBits;

};

std::ostream 			&operator<<(std::ostream & o, Fixed const & rhs);

#endif