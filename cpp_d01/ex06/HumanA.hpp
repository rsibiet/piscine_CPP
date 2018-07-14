/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:16:01 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 17:16:04 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
#include "Weapon.hpp"

class HumanA
{

public:
	
	Weapon			&weap;
	std::string		name;

	HumanA(std::string n, Weapon &w);
	~HumanA(void);
	void	attack(void);

};

#endif