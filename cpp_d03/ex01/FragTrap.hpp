/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:46:37 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/31 17:46:38 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include <iostream>
#include <cstdlib>

class FragTrap
{

public:

	std::string		name;
	int				hitPts;
	unsigned int	energyPts;

	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap 		&operator=(FragTrap const & src);
	
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			vaulthunter_dot_exe(std::string const & target);

private:

	unsigned int	_MaxHitPts;
	unsigned int	_MaxEnergyPts;
	unsigned int	_Lvl;
	unsigned int	_MelAttack;
	unsigned int	_RangAttack;
	unsigned int	_ADamageReduc;

};

#endif