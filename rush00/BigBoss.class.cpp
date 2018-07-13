/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigBoss.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:12:02 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 15:53:08 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigBoss.class.hpp"

std::string				BigBoss::form[11] =
{
"   xxxxxx        ",
"       xxxx      ",
"   xxxxxxxxxx  xx",
" xx  xxxx  xxxx  ",
" xx  xxxxxxxx    ",
"     xxxxxxxx    ",
" xx  xxxxxxxx    ",
" xx  xxxx  xxxx  ",
"   xxxxxxxxxx  xx",
"       xxxx      ",
"   xxxxxx        "
};

std::string				BigBoss::form2[11] =
{
"   xxxxxx        ",
"       xxxx      ",
" xxxxxxxxxxxx    ",
"x    xxxx  xxxxx ",
"     xxxxxxxx   x",
"     xxxxxxxx    ",
"     xxxxxxxx   x",
"x    xxxx  xxxxx ",
" xxxxxxxxxxxx    ",
"       xxxx      ",
"   xxxxxx        "
};

BigBoss::BigBoss(void): life(10), _time(0), _time2(0), _timeAnim(0), _anim(1)
{
	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	x = _maxwidth - 17;
	y = rand() % (_maxheight - 16) + 2;
	for (int i = 0; i < 16; i++)
		sh[i].direction = 'l';
	_direction = 'l';
	return ;
}

BigBoss::BigBoss(BigBoss const & src) { *this = src; return ; }

BigBoss::~BigBoss(void) { return ; }

BigBoss		&BigBoss::operator=(BigBoss const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

void		BigBoss::shoot(clock_t startTime)
{
	for (int i = 0; i < 3; i++)
	{
		if (sh[i].x == 1)
		{
			mvprintw(sh[i].y, sh[i].x, "  ");
			sh[i].x = 0;
		}
		if (sh[i].x != 0)
			sh[i].moveShoot(startTime);
	}
}

void BigBoss::cleanShoot(){
	for (int i = 0; i < 3; i++)
	{
			mvprintw(sh[i].y, sh[i].x, "  ");
			sh[i].y = 0;
			sh[i].x = 0;
	}
}

bool		BigBoss::bossIsAlive(void)
{
	if (life > 0)
		return true;
	for (int i = 0; i < 11; i++)
		mvprintw(y + i, x, "                 ");
	life = 10;
	return false;
}

void		BigBoss::moveBigBoss(clock_t startTime, Player pl)
{
	clock_t 	endTime = clock();
	clock_t 	clockTicksTaken = endTime - startTime;
	double 		timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	int 		move = rand() % 2;
	double 		sp1 = 0.1 * _randSp1;

	if (y + 5 >= (pl.y - 2) && y + 5 <= (pl.y + 2) &&
		sh[0].x == 0 && sh[1].x == 0 && sh[2].x == 0) {
		sh[0].x = x - 1;
		sh[0].y = y + 5;
		sh[1].x = x - 2;
		sh[1].y = y + 3;
		sh[2].x = x - 2;
		sh[2].y = y + 7;
	}
	shoot(startTime);
	if (timeInSeconds >= _time2 + sp1 && move == 1) {
		getmaxyx(stdscr, _maxheight, _maxwidth);
		_randSp1 = rand() % 4 + 1;
		for (int i = 0; i < 11; i++)
			mvprintw(y + i, x, "                 ");
		if (y < _maxheight - 14 && y + 5 < pl.y)
			y += 2;
		else if (y > 2 && y + 5 > pl.y)
			y -= 2;
		_time2 = timeInSeconds;
	}
	if (timeInSeconds >= _time + .1) {
		for (int i = 0; i < 11; i++)
			mvprintw(y + i, x, "                 ");
		if (x < _maxwidth / 2 + 8)
			_direction = 'r';
		else if (x > _maxwidth - 19)
			_direction = 'l';
		if (_direction == 'l')
			x--;
		else
			x++;
		_time = timeInSeconds;
	}
	if (timeInSeconds >= _timeAnim + 1) {
		_anim *= -1;
		_timeAnim = timeInSeconds;
	}
	attron(COLOR_PAIR(5));
	for (int i = 0; i < 11; i++)
	{
		if (_anim == 1)
			mvprintw(y + i, x, "%s", form[i].c_str());
		else
			mvprintw(y + i, x, "%s", form2[i].c_str());
	}
	refresh();
}
