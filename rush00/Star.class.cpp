/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:02:19 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 15:22:21 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.class.hpp"

Star::Star(void): Entity("."), _time(0)
{
	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	x = rand() % (_maxwidth - 1);
	y = rand() % (_maxheight - 4) + 1;
	return ;
}

Star::Star(Star const & src) : Entity(src) { *this = src; return ; }

Star::~Star(void) {	return ; }

Star			&Star::operator=(Star const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void			Star::dpStar(void)
{
	mvprintw(y, x, " ");
	x = _maxwidth - 2;
	y = rand() % (_maxheight - 4) + 1;
}

void			Star::moveStar(clock_t StartTime, int lvl)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - StartTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	double sp = 0.01 / lvl;
	if (timeInSeconds >= _time + sp)
	{
		mvprintw(y, x, " ");
		x-- ;
		_time = timeInSeconds;
		attron(COLOR_PAIR(8));
		mvprintw(y, x, "%s", getForm().c_str());
		refresh();
	}
	if (x <= 0)
		dpStar();
}
