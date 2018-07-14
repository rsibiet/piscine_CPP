/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:29:52 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 10:29:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H
#include "Zombie.hpp"

class ZombieEvent {

public:

	void			setZombieType(std::string type);
	Zombie*			newZombie(std::string name);
	void			randomChump(void);

private:

	std::string		_type;

};

#endif