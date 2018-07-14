/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:16:10 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 17:16:11 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n): name(n)
{
	this->weap = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void		HumanB::attack(void)
{
	std::cout << this->name << " attacks with his ";
	std::cout << this->weap->getType() << std::endl;
}

void		HumanB::setWeapon(Weapon &w)
{
	this->weap = &w;
}
