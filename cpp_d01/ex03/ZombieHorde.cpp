/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:16:24 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 14:16:25 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"


std::string		name_random(void)
{
    static const char alpha[] = "bcdfghjklmnpqrstvwxz";
    static const char alpha2[] = "aeiouy";
    static const char alpha3[] = "BCDFGHIJKLMNPQRSTVWXZ";
   	int 		len;
	char		s[15] = "\0";

	len = rand() % 6 + 3;
    s[0] = alpha3[rand() % (sizeof(alpha3) - 1)];
    for (int i = 1; i < len; ++i) {
        s[i] = alpha2[rand() % (sizeof(alpha2) - 1)];
        i++;
        s[i] = alpha[rand() % (sizeof(alpha) - 1)];
    }
    s[len] = 0;
    return (s);
}

ZombieHorde::ZombieHorde(int n): N(n)
{
	int	i = 0;
	this->zomb = new Zombie[n];

	srand (time(NULL));
	while (i < n)
	{
		this->zomb[i].type = "Radioactive";
		this->zomb[i].name = name_random();
		i++;
	}
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->zomb;
	return ;
}

void			ZombieHorde::announce(void)
{
	int	i = 0;

	while (i < this->N)
	{
		this->zomb[i].announce();
		i++;
	}
}
