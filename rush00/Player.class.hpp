/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:44:59 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:15:55 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>

class Player
{

public:

	Player(int x, int y);
	Player(Player const & src);
	virtual ~Player(void);

	Player 			&operator=(Player const & rhs);

	int						x, y, life;
	char					direction;
	void					movePlayer(clock_t startTime);
	void					dpPlayer(clock_t startTime);
	void					setTime(double time);
	void					printPlayer(int addTox, int addToy);

	static std::string		Spaceship[3];

private:

	int 					_maxheight, _maxwidth, _collision;
	double					_time;

};

#endif
