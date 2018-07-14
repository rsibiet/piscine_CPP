/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:29:59 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 10:30:01 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int				main(void)
{
	Zombie			zombieStack = Zombie("Boby", "Vomiters");

	ZombieEvent*	event = new ZombieEvent();
	event->setZombieType("DOOM");
	Zombie*			zombEvent = event->newZombie("Toto");

	event->randomChump();

	delete event;
	delete zombEvent;
	return (0);
}