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

class Fixed
{

public:

	Fixed(void);
	Fixed(Fixed const &f);
	~Fixed(void);

	Fixed				&operator=(Fixed const & nb);
	void 				setRawBits(int const raw);
	int 				getRawBits(void) const;

private:

	int					_fPoint;
	static const int	_nbBits;

};

#endif