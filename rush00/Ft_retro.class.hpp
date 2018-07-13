/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_retro.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:59:14 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 11:17:50 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_CLASS_HPP
# define FT_RETRO_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Player.class.hpp"
#include "Stone.class.hpp"
#include "Shoot.class.hpp"
#include "Enemy.class.hpp"
#include "Star.class.hpp"
#include "BigStone.class.hpp"
#include "BigBoss.class.hpp"

#define MAXH 70
#define MAXW 250

class Ft_retro
{

public:

	Ft_retro(void);
	Ft_retro(Ft_retro const & src);
	virtual ~Ft_retro(void);

	Ft_retro 		&operator=(Ft_retro const & rhs);
	int				start();

	int 			maxheight, maxwidth, score;

private:

	void			display(int i);
	bool			collision(void);
	bool			collisionBoss(void);
	void			dpTime(clock_t startTime);
	int				shoot(clock_t startTime, int i);
	int				checkStat(int a, int b, int j);
	void			controlStat(clock_t startTime);
	void			moveEntities(clock_t startTime);
	void			removeEntities(void);
	int				gameOver(void);

	static Player	_p;
	Stone			_s[32];
	Shoot			_sh[64];
	Enemy			_e[16];
	Star			_star[64];
	BigStone		_bigS[4];
	BigBoss			_boss;
	int				_nbStone, _nbShoot, _nbEnemy, _nbStar, _nbBigStone, _lvl;
	double			_time, _overh;
	bool			_stat, _lvlBoss;

};

#endif
