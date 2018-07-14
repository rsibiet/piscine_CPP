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

Fixed::Fixed(void): _fPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
	return ;
}

Fixed::Fixed(int const i): _fPoint(i * 256)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const i): _fPoint(roundf(i * 256.0))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int				Fixed::toInt(void) const
{
	return this->_fPoint / 256;
}

float			Fixed::toFloat(void) const
{
	return this->_fPoint / 256.0;
}

Fixed			&Fixed::operator=(Fixed const & nb)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fPoint = nb.getRawBits();
	return *this;
}

void			Fixed::setRawBits( int const raw )
{
	this->_fPoint = raw;
}

int				Fixed::getRawBits( void ) const
{
	return (this->_fPoint);
}

std::ostream &		operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.getRawBits() / 256.0;
	return o;
}

const int		Fixed::_nbBits = 8;
