/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:44:23 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/29 16:44:24 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string color_eye,
			int h, int w): 
 _height(h), _weight(w), _name(name), _color(color), _color_eye(color_eye)
{
	std::cout << this->_name << " is born ! It's a " << this->_color;
	std::cout << " poney with " << this->_color_eye << " eyes." << std::endl;
	std::cout << "Its height: " << this->_height << " cm." << std::endl;
	std::cout << "Its weight: " << this->_weight << " kg." << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << this->_name << " died !" << std::endl;
	return ;
}

void	Pony::makeSomeStuff(int sleep, int run)
{
	std::cout << this->_name << " sleep " << sleep << " hours." << std::endl;
	std::cout << this->_name << " run " << run << " minutes." << std::endl;
}
