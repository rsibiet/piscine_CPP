/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:44:27 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/29 16:44:29 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H
#include <iostream>

class Pony
{

public:

	Pony(std::string name, std::string color,
		std::string color_eye, int h, int w);
	~Pony(void);
	void			makeSomeStuff(int sleep, int run);

private:

	int 			_height;
	int 			_weight;
	std::string 	_name;
	std::string 	_color;
	std::string 	_color_eye;

};

#endif