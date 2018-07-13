/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigBoss.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:12:06 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 15:53:35 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGBOSS_CLASS_HPP
# define BIGBOSS_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Shoot.class.hpp"
#include "Player.class.hpp"

class BigBoss
{

public:

	BigBoss(void);
	BigBoss(BigBoss const & src);
	~BigBoss();

	BigBoss					&operator=(BigBoss const & rhs);

	int						x, y;
	void					moveBigBoss(clock_t startTime, Player pl);
	void					shoot(clock_t startTime);
	bool					bossIsAlive(void);
	void 					cleanShoot();

	Shoot				sh[3];
	int						life;

private:

	static std::string		form[11];
	static std::string		form2[11];
	double					_time, _time2, _timeAnim;
	int						_maxwidth, _maxheight, _randSp1, _anim;
	char					_direction;

};

#endif
