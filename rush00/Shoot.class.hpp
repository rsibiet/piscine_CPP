/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:25:46 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:16:02 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Entity.class.hpp"


class Shoot : public Entity
{

public:

	Shoot(void);
	Shoot(Shoot const & src);
	virtual ~Shoot(void);

	Shoot 					&operator=(Shoot const & rhs);

	int						x, y;
	char					direction;
	void					moveShoot(clock_t startTime);

private:

	double					_time;

};

#endif
