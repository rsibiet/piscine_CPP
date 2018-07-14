/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:47:40 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/01 12:47:41 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->name = name;
	this->hitPts = 100;
	this->energyPts = 50;
	this->_MaxHitPts = 100;
	this->_MelAttack = 20;
	this->_RangAttack = 15;
	this->_ADamageReduc = 3;
	this->_Lvl = 1;
	this->_MaxEnergyPts = 50;
	std::cout << "Booting sequence of new SC4V-TP complete. " << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src.name)
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

ScavTrap::~ScavTrap(void)
{ std::cout << "SC4V-TP is destroyed." << std::endl; return ; }

ScavTrap &		ScavTrap::operator=(ScavTrap const & rhs)
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

void		ScavTrap::challengeNewcomer(void)
{
	const char *challenge[] = {
								"Kill 50 Human Enemies.",
								"Get 50 kills with Melee.",
								"Kill 500 Enemies.",
								"Win 10 Duels.",
								"Kill 50 Guardian."
							  };

	std::cout << "SC4V-TP " << this->name << " make following challenge: ";
	std::cout << challenge[rand() % 5] << std::endl;
}

void		ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->name << " attacks ";
	std::cout << target << " at range, causing " << this->_RangAttack;
	std::cout << " points of damage !" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->name << " attacks ";
	std::cout << target << " at melee, causing " << this->_MelAttack;
	std::cout << " points of damage !" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPts + (int)this->_ADamageReduc - (int)amount) < 0)
		this->hitPts = 0;
	else
		this->hitPts -= (amount - this->_ADamageReduc);

	std::cout << "SC4V-TP " << this->name << " take ";
	std::cout << amount - this->_ADamageReduc;
	std::cout << " points of damage !" << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts + amount > this->_MaxHitPts)
		this->hitPts = this->_MaxHitPts;
	else
		this->hitPts += amount;
	std::cout << "SC4V-TP " << this->name << " has been repaired. It recover ";
	std::cout << amount << " points of energy !" << std::endl;
}