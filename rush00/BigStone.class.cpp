/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigStone.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:51:09 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:19:12 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigStone.class.hpp"

BigStone::BigStone(void): Entity("/_\\"), _time(0), _time2(0)
{
	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	x = rand() % (_maxwidth - 4) + 32;
	y = rand() % (_maxheight - 3) + 1;
	return ;
}

BigStone::BigStone(BigStone const & src) : Entity(src){ *this = src; return ; }

BigStone::~BigStone(void) {	return ; }

BigStone		&BigStone::operator=(BigStone const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void			BigStone::dpBigStone(void)
{
	mvprintw(y, x, "   ");
	x = _maxwidth - 4;
	y = rand() % (_maxheight - 3) + 1;
}

void			BigStone::moveBigStone(clock_t startTime, int lvl)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	double sp = 0.2 / lvl;
	double sp2 = 1.0 / lvl;

	if (timeInSeconds >= _time + sp)
	{
		mvprintw(y, x, "   ");
		x--;
		_time = timeInSeconds;
	}
	if (timeInSeconds >= _time2 + sp2)
	{
		 mvprintw(y, x, "   ");
		  y += 1;
		_time2 = timeInSeconds;
	}
	if (x <= 0 || y >= _maxheight - 2 || y <= 1)
		dpBigStone();
	attron(COLOR_PAIR(4));
	mvprintw(y, x, "%s", getForm().c_str());
	refresh();
}
