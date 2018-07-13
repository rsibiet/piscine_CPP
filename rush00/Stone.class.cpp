/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stone.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:26:51 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 15:15:35 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stone.class.hpp"

Stone::Stone(void): Entity("o"), _time(0)
{
	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	x = rand() % (_maxwidth - 2) + 32;
	y = rand() % (_maxheight - 4) + 1;
	return ;
}

Stone::Stone(Stone const & src) : Entity(src) { *this = src; return ; }

Stone::~Stone(void) { return ; }

Stone			&Stone::operator=(Stone const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void			Stone::dpStone(void)
{
	mvprintw(y, x, " ");
	x = _maxwidth - 2;
	y = rand() % (_maxheight - 4) + 1;
}

void			Stone::moveStone(clock_t startTime, int lvl)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	double sp = 0.2 / lvl;
	if (timeInSeconds >= _time + sp)
	{
		mvprintw(y, x, " ");
		x--;
		_time = timeInSeconds;
	}
	if (x == 0)
		dpStone();
	attron(COLOR_PAIR(3));
	mvprintw(y, x, "%s", getForm().c_str());
	refresh();
}
