/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:15:45 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 17:15:47 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w):  weap(w), name(n)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void		HumanA::attack(void)
{
	std::cout << this->name << " attacks with his ";
	std::cout << this->weap.getType() << std::endl;
}
