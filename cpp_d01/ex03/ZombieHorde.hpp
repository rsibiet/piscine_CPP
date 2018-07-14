/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:16:33 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 14:16:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H
#include "Zombie.hpp"

class ZombieHorde {

public:
	Zombie			*zomb;
	int				N;

	ZombieHorde(int N);
	~ZombieHorde(void);
	void			announce(void);

};

#endif
