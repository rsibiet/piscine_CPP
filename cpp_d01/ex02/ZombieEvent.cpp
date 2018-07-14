/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:29:48 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 10:29:49 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie* 	zomb = new Zombie(name, this->_type);
	return (zomb);
}

std::string		name_random(void)
{
    static const char alpha[] = "bcdfghjklmnpqrstvwxz";
    static const char alpha2[] = "aeiouy";
    static const char alpha3[] = "BCDFGHIJKLMNPQRSTVWXZ";
   	int 		len;
	char		s[15] = "\0";

	srand (time(NULL));
	len = rand() % 6 + 3;
    s[0] = alpha3[rand() % (sizeof(alpha3) - 1)];
    for (int i = 1; i < len; ++i) {
        s[i] = alpha2[rand() % (sizeof(alpha2) - 1)];
        i++;
        s[i] = alpha[rand() % (sizeof(alpha) - 1)];
    }
    s[len] = '\0';
    return (s);
}

void		ZombieEvent::randomChump(void)
{
	Zombie		randZombie = Zombie(name_random(), this->_type);
}