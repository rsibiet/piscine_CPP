/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 10:40:16 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 16:02:16 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(void): Entity("x"), _time(0), _time2(0), _time3(0), _sp3(10)
{
	int tmp = rand() % 20 + 4;

	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	x = rand() % (_maxwidth - 2) + _maxwidth;
	y = rand() % (_maxheight - 4) + 1;
	_randSp1 = 1;
	sh.direction = 'l';
	_sp3 = tmp;
	return ;
}

Enemy::Enemy(Enemy const & src) : Entity(src) { *this = src; return ; }

Enemy::~Enemy(void) { return ; }

Enemy			&Enemy::operator=(Enemy const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->sh = rhs.sh;
	return *this;
}

void			Enemy::shoot(clock_t startTime)
{
	if (sh.x == 1)
	{
		mvprintw(sh.y, sh.x, " ");
		sh.x = 0;
	}
	if (sh.x != 0)
		sh.moveShoot(startTime);
}

void			Enemy::cleanShoot()
{
	mvprintw(sh.y, sh.x, " ");
	sh.y = 0;
	sh.x = 0;
}

void			Enemy::dpEnemy(void)
{
	mvprintw(y, x, " ");
	x = _maxwidth - 2;
	y = rand() % (_maxheight - 4) + 1;
}

void			Enemy::moveEnemy(clock_t startTime, int lvl)
{
	clock_t 	endTime = clock();
	clock_t 	clockTicksTaken = endTime - startTime;
	double 		timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	int 		down = rand() % 2;
	int 		up = rand() % 2;
	double 		sp1 = 0.5 / lvl * _randSp1;
	double 		sp2 = 0.1 / lvl;
	int			tmp = 0;

	if (_time3 == 0)
		_time3 = timeInSeconds;
	if (timeInSeconds >= _time3 + _sp3 && sh.x == 0) {
		tmp = rand() % 20 + 1;
		_sp3 = tmp / lvl;
		sh.x = x - 1;
		sh.y = y;
		_time3 = timeInSeconds;
	}
	shoot(startTime);
	if (timeInSeconds >= _time2 + sp1 && down != up) {
		_randSp1 = rand() % 4 + 1;
		mvprintw(y, x, " ");
		if (y < _maxheight - 2)
			y += down;
		y -= up;
		_time2 = timeInSeconds;
	}
	if (timeInSeconds >= _time + sp2) {
		mvprintw(y, x, " ");
		x--;
		_time = timeInSeconds;
	}
	if (x == 0)
		dpEnemy();
	attron(COLOR_PAIR(5));
	mvprintw(y, x, "%s", getForm().c_str());
	refresh();
}
