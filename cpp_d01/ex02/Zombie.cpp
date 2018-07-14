/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:29:33 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 10:29:35 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type):
				 type(type), name(name)
{
	this->announce();
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is deleted." << std::endl;
	return ;
}

void			Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}