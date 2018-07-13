/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 10:40:22 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/18 15:58:41 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Shoot.class.hpp"
#include "Entity.class.hpp"

class Enemy : public Entity
{
public:

	Enemy(void);
	Enemy(Enemy const & src);
	virtual ~Enemy(void);

	Enemy					&operator=(Enemy const & rhs);

	int						x, y;
	char					direction;
	void					moveEnemy(clock_t startTime, int lvl);
	void					shoot(clock_t startTime);
	void					dpEnemy(void);
	void					cleanShoot();
	Shoot			sh;

private:
	double					_time, _time2, _time3, _sp3;
	int						_maxheight, _maxwidth, _randSp1;


};

#endif
