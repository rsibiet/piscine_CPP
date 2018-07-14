/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:00:38 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/01 15:00:39 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name)
{ std::cout << "CL4P-TP created. " << std::endl; return ; }

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	this->hitPts = src.hitPts;
	this->energyPts = src.energyPts;
	this->_MaxHitPts = src._MaxHitPts;
	this->_MelAttack = src._MelAttack;
	this->_RangAttack = src._RangAttack;
	this->_ADamageReduc = src._ADamageReduc;
	this->_Lvl = src._Lvl;
	this->_MaxEnergyPts = src._MaxEnergyPts;
	return ;
}

ClapTrap::~ClapTrap(void)
{ std::cout << "CL4P-TP is destroyed." << std::endl; return ; }

ClapTrap 	&ClapTrap::operator=(ClapTrap const & rhs)
{
	this->hitPts = rhs.hitPts;
	this->energyPts = rhs.energyPts;
	this->_MaxHitPts = rhs._MaxHitPts;
	this->_MelAttack = rhs._MelAttack;
	this->_RangAttack = rhs._RangAttack;
	this->_ADamageReduc = rhs._ADamageReduc;
	this->_Lvl = rhs._Lvl;
	this->_MaxEnergyPts = rhs._MaxEnergyPts;
	return (*this);
}

void		ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << " attacks ";
	std::cout << target << " at range, causing " << this->_RangAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << " attacks ";
	std::cout << target << " at melee, causing " << this->_MelAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPts + (int)this->_ADamageReduc - (int)amount) < 0)
		this->hitPts = 0;
	else
		this->hitPts -= (amount - this->_ADamageReduc);

	std::cout << this->name << " take ";
	std::cout << amount - this->_ADamageReduc;
	std::cout << " points of damage !" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts + amount > this->_MaxHitPts)
		this->hitPts = this->_MaxHitPts;
	else
		this->hitPts += amount;
	std::cout << this->name << " has been repaired. It recover ";
	std::cout << amount << " points of energy !" << std::endl;
}
