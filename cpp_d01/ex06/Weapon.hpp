/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:16:31 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 17:16:32 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#include <iostream>

class Weapon
{

public:

	std::string			type;

	Weapon(std::string weap);
	~Weapon(void);
	const std::string	&getType(void);
	void				setType(std::string tp);

};

#endif