/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:46:30 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/31 17:46:32 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): name(name), hitPts(100), energyPts(100),
									  _MaxHitPts(100), _MelAttack(30),
									  _RangAttack(20), _ADamageReduc(5)
{
	this->_Lvl = 1;
	this->_MaxEnergyPts = 100;
	std::cout << "Booting sequence of new FR4G-TP complete. " << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
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

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP is destroyed." << std::endl;
	return ;
}

FragTrap &		FragTrap::operator=(FragTrap const & rhs)
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

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks ";
	std::cout << target << " at range, causing " << this->_RangAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name << " attacks ";
	std::cout << target << " at melee, causing " << this->_MelAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		FragTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPts + (int)this->_ADamageReduc - (int)amount) < 0)
		this->hitPts = 0;
	else
		this->hitPts -= (amount - this->_ADamageReduc);
	std::cout << "FR4G-TP " << this->name << " take ";
	std::cout << amount - this->_ADamageReduc;
	std::cout << " points of damage !" << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts + amount > this->_MaxHitPts)
		this->hitPts = this->_MaxHitPts;
	else
		this->hitPts += amount;
	std::cout << "FR4G-TP " << this->name << " has been repaired. It recover ";
	std::cout << amount << " points of energy !" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	const char *attack[] = {
								"Torgue Fiesta",
								"Funzerker",
								"Pirate Ship Mode",
								"Laser Inferno",
								"One Shot Wonder"
							};

	if (this->energyPts < 25)
		std::cout <<  "FR4G-TP " << this->name << " is out of energy." << std::endl;
	else
	{
		std::cout << "FR4G-TP " << this->name << " attacks "<<  target;
		std::cout << " at " << attack[rand() % 5] << std::endl;
		this->energyPts -= 25;
	}
}
