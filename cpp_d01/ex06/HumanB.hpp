/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:16:15 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 17:16:17 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
#include "Weapon.hpp"

class HumanB
{

public:

	Weapon			*weap;
	std::string		name;

	HumanB(std::string n);
	~HumanB(void);
	void	attack(void);
	void	setWeapon(Weapon &w);

};

#endif