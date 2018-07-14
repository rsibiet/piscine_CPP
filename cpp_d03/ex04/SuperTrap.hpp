/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:43:40 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/13 11:43:42 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{

public:

	SuperTrap(std::string name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap(void);
	SuperTrap		&operator=(SuperTrap const & rhs);

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			ninjaShoebox(ClapTrap & target);
	void			ninjaShoebox(ScavTrap & target);
	void			ninjaShoebox(FragTrap & target);
	void			ninjaShoebox(NinjaTrap & target);

	void			vaulthunter_dot_exe(std::string const & target);

};

#endif