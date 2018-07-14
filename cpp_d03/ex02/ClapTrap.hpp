/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:00:45 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/01 15:00:46 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <iostream>

class ClapTrap
{

public:

	std::string		name;
	int				hitPts;
	unsigned int	energyPts;

	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap 		&operator=(ClapTrap const & rhs);
	
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

protected:

	unsigned int	_MaxHitPts;
	unsigned int	_MaxEnergyPts;
	unsigned int	_Lvl;
	unsigned int	_MelAttack;
	unsigned int	_RangAttack;
	unsigned int	_ADamageReduc;

};

#endif