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

#include "ZombieHorde.hpp"

int				main(void)
{
	ZombieHorde		horde = ZombieHorde(10);

	std::cout << "An horde of 10 zombies come !" << std::endl;
	horde.announce();
	return (0);
}