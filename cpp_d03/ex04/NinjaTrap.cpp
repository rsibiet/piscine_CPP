/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:47:51 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/01 16:47:53 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name): ClapTrap(name)
{
	this->name = name;
	this->hitPts = 60;
	this->energyPts = 120;
	this->_MaxHitPts = 60;
	this->_MelAttack = 60;
	this->_RangAttack = 5;
	this->_ADamageReduc = 0;
	this->_Lvl = 1;
	this->_MaxEnergyPts = 120;
	std::cout << "Booting sequence of new NINJ4-TP complete. " << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src): ClapTrap(src.name)
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

NinjaTrap::~NinjaTrap(void)
{ std::cout << "NINJ4-TP is destroyed." << std::endl; return ; }

NinjaTrap 	&NinjaTrap::operator=(NinjaTrap const & rhs)
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

void		NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << this->name << " attacks ";
	std::cout << target << " at range, causing " << this->_RangAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NINJ4-TP " << this->name << " attacks ";
	std::cout << target << " at melee, causing " << this->_MelAttack;
	std::cout << " points of damage !" << std::endl;	
}

void		NinjaTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPts + (int)this->_ADamageReduc - (int)amount) < 0)
		this->hitPts = 0;
	else
		this->hitPts -= (amount - this->_ADamageReduc);

	std::cout << "NINJ4-TP " << this->name << " take ";
	std::cout << amount - this->_ADamageReduc;
	std::cout << " points of damage !" << std::endl;
}

void		NinjaTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts + amount > this->_MaxHitPts)
		this->hitPts = this->_MaxHitPts;
	else
		this->hitPts += amount;
	std::cout << "NINJ4-TP " << this->name << " has been repaired. It recover ";
	std::cout << amount << " points of energy !" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	std::cout << "NINJ4-TP " << this->name << " scared ";
	std::cout << target.name << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << "NINJ4-TP " << this->name << " scorn ";
	std::cout << target.name << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << "NINJ4-TP " << this->name << " dance with ";
	std::cout << target.name << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << "NINJ4-TP " << this->name << " joke with ";
	std::cout << target.name << std::endl;
}
