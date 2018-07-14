/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:47:46 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/01 12:47:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include <iostream>
#include <cstdlib>

class ScavTrap
{

public:

	std::string		name;
	int				hitPts;
	unsigned int	energyPts;

	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap 		&operator=(ScavTrap const & rhs);

	
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			challengeNewcomer(void);

private:

	unsigned int	_MaxHitPts;
	unsigned int	_MaxEnergyPts;
	unsigned int	_Lvl;
	unsigned int	_MelAttack;
	unsigned int	_RangAttack;
	unsigned int	_ADamageReduc;
	
};

#endif