/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:19:22 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/31 10:19:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void): _fPoint(0) { return ; }

Fixed::Fixed(Fixed const &f)
{
	*this = f;
	return ;
}

Fixed::Fixed(int const i): _fPoint(i * 256) { return ; }

Fixed::Fixed(float const i): _fPoint(roundf(i * 256.0)) { return ; }

Fixed::~Fixed(void) { return ; }

int				Fixed::toInt(void) const { return this->_fPoint / 256; }

float			Fixed::toFloat(void) const { return this->_fPoint / 256.0; }

Fixed	&		Fixed::operator=(Fixed const & nb)
{
	this->_fPoint = nb.getRawBits();
	return *this;
}

bool			Fixed::operator>(Fixed const & rhs) 
{ return this->_fPoint > rhs.getRawBits(); }

bool			Fixed::operator<(Fixed const & rhs)
{ return this->_fPoint < rhs.getRawBits(); }

bool			Fixed::operator>=(Fixed const & rhs)
{ return !(this->_fPoint >= rhs.getRawBits()); }

bool			Fixed::operator<=(Fixed const & rhs)
{ return !(this->_fPoint <= rhs.getRawBits()); }

bool			Fixed::operator==(Fixed const & rhs)
{ return (this->_fPoint == rhs.getRawBits()); }

bool			Fixed::operator!=(Fixed const & rhs)
{ return !(this->_fPoint != rhs.getRawBits()); }

Fixed			Fixed::operator+(Fixed const & nb) const
{
	Fixed res;
	res._fPoint = this->_fPoint + nb.getRawBits();
	return res;
}

Fixed			Fixed::operator-(Fixed const & nb) const
{
	Fixed res;
	res._fPoint = this->_fPoint - nb.getRawBits();
	return res;
}

Fixed			Fixed::operator*(Fixed const & nb) const
{
	Fixed res;
	res._fPoint = this->_fPoint * nb.getRawBits() / 256;
	return res;
}

Fixed			Fixed::operator/(Fixed const & nb) const
{
	Fixed res;
	res._fPoint = this->_fPoint / nb.getRawBits();
	return res;
}

Fixed &			Fixed::operator++(void)
{
	this->_fPoint += 1;
	return *this;
}

Fixed			Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &			Fixed::operator--(void)
{
	this->_fPoint -= 1;
	return *this;
}

Fixed			Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &			Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed &			Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

void			Fixed::setRawBits( int const raw ) { this->_fPoint = raw; }

int				Fixed::getRawBits( void ) const { return (this->_fPoint); }

std::ostream &		operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.getRawBits() / 256.0;
	return o;
}

const int		Fixed::_nbBits = 8;
