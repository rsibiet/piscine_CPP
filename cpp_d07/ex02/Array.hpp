/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:15:13 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/21 10:15:17 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
#include <iostream>
#include <stdexcept>

template < typename T >
class Array
{

public:

	Array(void): _size(0)
	{
		this->_array = new T[0];
		return ;
	}

	Array(unsigned int n)
	{
		this->_size = n;
		this->_array = new T[n];
		return ;
	}

	Array(Array const &src)
	{
		this->_size = src.getSize();

		this->_array = new T[_size];
		for(unsigned int i = 0; i < _size; i++)
			this->_array[i] = src._array[i];
	}

	~Array(void)
	{
		delete [] this->_array;
		return ;
	}

	T						getArray(void) const
	{
		return (this->_array);
	}

	unsigned int			getSize(void) const
	{
		return (this->_size);
	}

	Array					&operator=(Array const &rhs)
	{
		delete [] this->_array;
		this->_array = rhs._array;
		this->_size = rhs._size;
		return *this;
	}

	T						&operator[](unsigned int n)
	{
		if (n > _size - 1)
			throw std::overflow_error("This element is out of the limits.");
		return this->_array[n];
	}

	unsigned int			size(void) { return this->_size; }

private:

	T 						*_array;
	unsigned int 			_size;

};

#endif