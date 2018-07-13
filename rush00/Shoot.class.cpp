/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:25:37 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:11:31 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot(void): Entity("-"), x(0), y(0), direction(0), _time(0)
{
	return ;
}

Shoot::Shoot(Shoot const & src) : Entity(src) { *this = src; return ; }

Shoot::~Shoot(void) { return ; }

Shoot		&Shoot::operator=(Shoot const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void			Shoot::moveShoot(clock_t startTime)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	if (timeInSeconds >= _time + .005)
	{
		mvprintw(y, x, " ");
		if (direction == 'r')
			x++;
		else if (direction == 'l')
			x--;
		_time = timeInSeconds;
	}
	if (x != 0)
	{
		attron(COLOR_PAIR(1));
		mvprintw(y, x, "%s", getForm().c_str());
		refresh();
	}
}
