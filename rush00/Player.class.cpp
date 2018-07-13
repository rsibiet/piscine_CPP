/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:44:54 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:14:46 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

std::string				Player::Spaceship[3] = {"  |\\", "+---)>", "  |/"};

Player::Player(int x, int y): x(x), y(y), life(5), _collision(5), _time(0)
{
	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	return ;
}

Player::Player(Player const & src) { *this = src; return ; }

Player::~Player(void) { return ; }

Player 					&Player::operator=(Player const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->life = rhs.life;
	this->direction = rhs.direction;
	return *this;
}

void					Player::setTime(double time) { this->_time = time; }

void					Player::dpPlayer(clock_t startTime)
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

	if (_time == 0)
		_time = timeInSeconds - .1;
	if (_collision == life + 1)
	{
		_time = timeInSeconds;
		_collision--;
	}
	if (_collision == 1)
		_collision = 5;
	attron(COLOR_PAIR(1));
	if (timeInSeconds >= _time + .05)
		attron(COLOR_PAIR(6));
	for (int i = 0; i < 3; i++)
	mvprintw(y + i - 1, x, "%s", Spaceship[i].c_str());
	refresh();
}

void					Player::printPlayer(int addTox, int addToy)
{
	mvprintw(y - 1, x, "    ");
	mvprintw(y, x, "      ");
	mvprintw(y + 1, x, "    ");
	direction = 'x';
	x += addTox;
	y += addToy;
}

void					Player::movePlayer(clock_t startTime)
{
	int 	tmp = getch();

	switch(tmp)
	{
		case KEY_LEFT:
			direction = 'l';
			break ;
		case KEY_UP:
			direction = 'u';
			break ;
		case KEY_DOWN:
			direction = 'd';
			break ;
		case KEY_RIGHT:
			direction = 'r';
			break ;
		case 'q':
			direction = 'q';
			break ;
		case ' ':
			direction = ' ';
			break ;
	}
	if (direction == 'l' && x > 0)
		printPlayer(-2, 0);
	else if (direction == 'r' && x < _maxwidth / 2 - 2)
		printPlayer(2, 0);
	else if (direction == 'u')
		printPlayer(0, -1);
	else if (direction == 'd' && y < _maxheight - 2)
		printPlayer(0, 1);
	dpPlayer(startTime);
}
