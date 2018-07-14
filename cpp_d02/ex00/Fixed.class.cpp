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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
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
	return ;
}

int				Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fPoint);
}

const int		Fixed::_nbBits = 8;
