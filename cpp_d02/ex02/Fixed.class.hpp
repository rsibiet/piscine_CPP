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

	Fixed &					operator=(Fixed const & nb);
	bool					operator>(Fixed const & rhs);
	bool					operator<(Fixed const & rhs);
	bool					operator>=(Fixed const & rhs);
	bool					operator<=(Fixed const & rhs);
	bool					operator==(Fixed const & rhs);
	bool					operator!=(Fixed const & rhs);
	Fixed					operator+(Fixed const & rhs) const;
	Fixed					operator-(Fixed const & rhs) const;
	Fixed					operator*(Fixed const & rhs) const;
	Fixed					operator/(Fixed const & rhs) const;
	Fixed &					operator++(void);
	Fixed					operator++(int);
	Fixed &					operator--(void);
	Fixed					operator--(int);

	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);
	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);

	void 					setRawBits(int const raw);
	int 					getRawBits(void) const;
	float					toFloat(void) const;
	int						toInt(void) const; 

private:

	int						_fPoint;
	static const int		_nbBits;

};

std::ostream &			operator<<(std::ostream & o, Fixed const & rhs);

#endif