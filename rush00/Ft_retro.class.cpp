/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_retro.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:59:09 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 16:02:46 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_retro.class.hpp"

Player			Ft_retro::_p = Player(0, 0);

Ft_retro::Ft_retro(void): maxheight(0), maxwidth(0), score(0),
						  _nbStone(32), _nbShoot(64), _nbEnemy(16),
						  _nbStar(64), _nbBigStone(4), _lvl(1),
						  _time(0.0), _overh(0.0), _stat(true), _lvlBoss(false)
{
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, maxheight, maxwidth);
	start_color();
	clear();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_RED);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	Ft_retro::display(1);

	return ;
}

void			Ft_retro::display(int i)
{
	attron(COLOR_PAIR(6));
	while (i < maxwidth - 1)
	{
		move(0, i);
		addch('-');
		i++;
	}
	i = 1;
	while (i < maxwidth - 1)
	{
		move(maxheight - 2, i);
		addch('-');
		i++;
	}
	refresh();
}

Ft_retro::Ft_retro(Ft_retro const & src)
{
	*this = src;
	return ;
}

Ft_retro::~Ft_retro(void)
{
	nodelay(stdscr, false);
	endwin();
	return ;
}

Ft_retro 		&Ft_retro::operator=(Ft_retro const & shs)
{
	this->maxheight = shs.maxheight;
	this->maxwidth = shs.maxwidth;
	this->score = shs.score;
	return *this;
}

void			Ft_retro::dpTime(clock_t startTime)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	if (timeInSeconds >= _time + .1)
	{
		display(1);
		_time = timeInSeconds;
		attron(COLOR_PAIR(6));
		mvprintw(maxheight - 1, 0, " Time: %.1lf", _time);
		mvprintw(maxheight - 1, maxwidth/4, "| Score: %d", score);
		mvprintw(maxheight - 1, 2 * maxwidth/4, "| Life: %d", _p.life);
		if (_lvlBoss == true)
		{
			attron(COLOR_PAIR(1));
			mvprintw(maxheight - 1, 2 * maxwidth/4 + 12, "| BOSS: %d  ", _boss.life);
		}
		else
			mvprintw(maxheight - 1, 2 * maxwidth/4 + 12, "              ");
		attron(COLOR_PAIR(6));
		mvprintw(maxheight - 1, 3 * maxwidth/4, "|");
		refresh();
	}
}

void			Ft_retro::controlStat(clock_t startTime)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	attron(COLOR_PAIR(2));
	if (_overh == 0.0)
	{
		_overh = timeInSeconds;
		mvprintw(maxheight - 1, 3 * maxwidth/4 + 2, "Ready to shoot !          ");
	}
	if (timeInSeconds >= _overh + 3.0)
	{
		mvprintw(maxheight - 1, 3 * maxwidth/4 + 2, "Ready to shoot !          ");
		_stat = true;
		_overh = timeInSeconds;
	}
	if (_stat == false)
	{
		attron(COLOR_PAIR(1));
		mvprintw(maxheight - 1, 3 * maxwidth/4 + 2, "OVERHEATE !                          ");
		attron(COLOR_PAIR(7));
		for (float i = 0.0 ; i < 3 - (timeInSeconds - _overh); i += 0.125)
			mvprintw(maxheight - 1, 3 * maxwidth/4 + 14 + 8 * i, " ");
	}
	attron(COLOR_PAIR(1));
	refresh();
}

int				Ft_retro::checkStat(int a, int b, int j)
{
	if (j == _nbShoot)
		j = 0;
	if (j >= 0 && _sh[j].x != 0)
		_stat = false;
	_sh[j].direction = 'r';
	_sh[j].x = _p.x + a;
	_sh[j].y = _p.y + b;
	return (j + 1);
}

int				Ft_retro::shoot(clock_t startTime, int j)
{
	int 	i = 0;

	_p.direction = 'x';

	if (_stat == true && ((j == 0 && (_sh[_nbShoot - 1].x > _p.x + 7 ||
				    _sh[_nbShoot - 1].x == 0)) ||
		(j > 0 && (_sh[j - 1].x > _p.x + 7 ||
			       _sh[j - 1].x == 0))))
	{
		j = checkStat(6, 0, j);
		j = checkStat(4, -1, j);
		j = checkStat(4, 1, j);
	}
	while(i < _nbShoot)
	{
		if (_sh[i].x >= maxwidth - 2)
		{
			mvprintw(_sh[i].y, _sh[i].x, " ");
			_sh[i].x = 0;
		}
		if (_sh[i].x != 0)
			_sh[i].moveShoot(startTime);
		i++;
	}
	return j;
}

int				Ft_retro::gameOver(void)
{
	int 	tmp = getch();

	_p.direction = 'x';
	attron(COLOR_PAIR(1));
	mvprintw(maxheight / 2 - 2, maxwidth / 2 - 20, "   ___ ");
	mvprintw(maxheight / 2 - 1, maxwidth / 2 - 20, "  / __|__ _ _ __  ___   _____ _____ _ _ ");
	mvprintw(maxheight / 2, maxwidth / 2 - 20, " | (_ / _` | '  \\/ -_) / _ \\ V / -_) '_|");
	mvprintw(maxheight / 2 + 1, maxwidth / 2 - 20, "  \\___\\__,_|_|_|_\\___| \\___/\\_/\\___|_|  ");
	attron(COLOR_PAIR(6));
	mvprintw(maxheight / 2 + 3, maxwidth / 2 - 6, "Score : %d", score);
	mvprintw(maxheight / 2 + 4, maxwidth / 2 - 8, "Press r to retry");
	mvprintw(maxheight / 2 + 5, maxwidth / 2 - 6, "or q to quit");
	_p.life = 5;
	_p.setTime(0);
	switch(tmp)
	{
		case 'r':
			return 1;
		case 'q':
			return 0;
	}
	return -1;
}

int 			controleWindowSize(int maxwidth, int maxheight)
{
	int 	maxh = 0;
	int 	maxw = 0;

	getmaxyx(stdscr, maxh, maxw);
	if (maxheight != maxh || maxwidth != maxw)
	{
		nodelay(stdscr, false);
		getch();
		clear();
		endwin();
		std::cout << "\033[31mYou can not resize window in game." << std::endl;
		std::cout << "\033[32mGame over\033[0m" << std::endl;
		return (-1);
	}
	return (0);
}

void			Ft_retro::removeEntities(void)
{
	for(int i = 0; i < _nbEnemy; i++)
		mvprintw(_e[i].y, _e[i].x, " ");
	for(int i = 0; i < _nbStone; i++)
		mvprintw(_s[i].y, _s[i].x, " ");
	for(int i = 0; i < _nbBigStone; i++)
		mvprintw(_bigS[i].y, _bigS[i].x, "   ");
}

// void			Ft_retro::nextLvl()

void			Ft_retro::moveEntities(clock_t startTime)
{
	_p.movePlayer(startTime);
	for (int i = 0; i < _nbStar; i++)
		_star[i].moveStar(startTime, _lvl);
	if (_lvlBoss == false)
	{
		for (int i = 0; i < _nbEnemy; i++)
			_e[i].moveEnemy(startTime, _lvl);
		for (int i = 0; i < _nbStone; i++)
			_s[i].moveStone(startTime, _lvl);
		for (int i = 0; i < _nbBigStone; i++)
			_bigS[i].moveBigStone(startTime, _lvl);
		if (score != 0 && score % 100 == 0)
		{
			_lvlBoss = true;
			for(int i = 0; i < _nbShoot; i++){
				mvprintw(_sh[i].y, _sh[i].x, " ");
				_sh[i].y = 0;
				_sh[i].x = 0;
			}
			for(int i = 0; i < maxwidth; i++){
				for(int j = 0; j < maxheight; j++)
				{
					mvprintw(i, j, " ");
				}
			}
			_boss.cleanShoot();
			for(int i = 0; i < _nbEnemy; i++)
			{
				_e[i].cleanShoot();
			}
		}
	}
	else
	{
		removeEntities();
		_boss.moveBigBoss(startTime, _p);
		_lvlBoss = _boss.bossIsAlive();
		if (_lvlBoss == false)
		{
			startTime = clock();
			// nextLvl(startTime);
			for(int i = 0; i < 3; i++)
				mvprintw(_p.y - 1 + i, _p.x, "       ");
			_p.x = 2;
			_p.y = maxheight / 2;
			for(int i = 0; i < _nbShoot; i++){

				mvprintw(_sh[i].y, _sh[i].x, " ");
				_sh[i].y = 0;
				_sh[i].x = 0;
			}
			for(int i = 0; i < maxwidth; i++){
				for(int j = 0; j < maxheight; j++)
				{
					mvprintw(i, j, " ");
				}
			}
			_boss.cleanShoot();
			for(int i = 0; i < _nbEnemy; i++)
			{
				_e[i].cleanShoot();
			}
		}
	}
}

int  			Ft_retro::start(void)
{
	clock_t startTime = clock();
	srand((int)time(NULL));
	int 	j = 0;
	int 	ret = 0;

	_p.x = 2;
	_p.y = maxheight / 2;
	while (42)
	{
		if (controleWindowSize(maxwidth, maxheight) == -1)
			return (0);
		dpTime(startTime);
		moveEntities(startTime);
		if ((_lvlBoss == false && collision()) ||
			(_lvlBoss == true && collisionBoss()) ||
			_p.direction == 'q') {
			while ((ret = gameOver()) == -1)
				;
			return (ret);
		}
		if (_p.direction == ' ')
			j = shoot(startTime, j);
		else
			shoot(startTime, -1);
		controlStat(startTime);
	}
	return (0);
}
