/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:43:35 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/13 11:43:36 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name): FragTrap(name), NinjaTrap(name)
										ClapTrap(name)
{
	this->name = name;
	this->hitPts = FragTrap::hitPts;
	this->_MaxHitPts = 60;
	this->energyPts = 120;
	this->_MaxEnergyPts = 120;
	this->_Lvl = 1;
	this->_MelAttack = 30;
	this->_RangAttack = 20;
	this->_ADamageReduc = 5;
	std::cout << "Booting sequence of new SUPER-TP complete. " << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & src): FragTrap(name), NinjaTrap(name)
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

SuperTrap::~SuperTrap(void)
{ std::cout << "SUPER-TP is destroyed." << std::endl; return ; }

SuperTrap 	&SuperTrap::operator=(SuperTrap const & rhs)
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

void		SuperTrap::rangedAttack(std::string const & target)
{
	std::cout << "SUPER-TP " << this->name << " attacks ";
	std::cout << target << " at range, causing " << this->_RangAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		SuperTrap::meleeAttack(std::string const & target)
{
	std::cout << "SUPER-TP " << this->name << " attacks ";
	std::cout << target << " at melee, causing " << this->_MelAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		SuperTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPts + (int)this->_ADamageReduc - (int)amount) < 0)
		this->hitPts = 0;
	else
		this->hitPts -= (amount - this->_ADamageReduc);

	std::cout << "SUPER-TP " << this->name << " take ";
	std::cout << amount - this->_ADamageReduc;
	std::cout << " points of damage !" << std::endl;
}

void		SuperTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts + amount > this->_MaxHitPts)
		this->hitPts = this->_MaxHitPts;
	else
		this->hitPts += amount;
	std::cout << "SUPER-TP " << this->name << " has been repaired. It recover ";
	std::cout << amount << " points of energy !" << std::endl;
}

void		SuperTrap::vaulthunter_dot_exe(std::string const & target)
{
	const char *attack[] = {
								"Torgue Fiesta",
								"Funzerker",
								"Pirate Ship Mode",
								"Laser Inferno",
								"One Shot Wonder"
							};

	if (this->energyPts < 25)
		std::cout <<  "SUPER-TP " << this->name << " is out of energy." << std::endl;
	else
	{
		std::cout << "SUPER-TP " << this->name << " attacks "<<  target;
		std::cout << " at " << attack[rand() % 5] << std::endl;
		this->energyPts -= 25;
	}
}

void		SuperTrap::ninjaShoebox(ClapTrap & target)
{
	std::cout << "SUPER-TP " << this->name << " scared ";
	std::cout << target.name << std::endl;
}

void		SuperTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << "SUPER-TP " << this->name << " scorn ";
	std::cout << target.name << std::endl;
}

void		SuperTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << "SUPER-TP " << this->name << " dance with ";
	std::cout << target.name << std::endl;
}

void		SuperTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << "SUPER-TP " << this->name << " joke with ";
	std::cout << target.name << std::endl;
}
