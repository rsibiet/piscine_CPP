/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:28:15 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 18:47:44 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_retro.class.hpp"


bool			Ft_retro::collisionBoss(void)
{
	if (_p.y == 1 || _p.y == maxheight - 3)
		return true;
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 6; j++)
			if (_boss.sh[i].x == _p.x + j && _boss.sh[i].y == _p.y)// player / shoot boss
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_boss.sh[i].x = 0;
			}
		for(int j = 2; j < 4; j++)						// player sides / shoot boss
			if (_boss.sh[i].x == _p.x + j &&
				 (_boss.sh[i].y == _p.y + 1 || _boss.sh[i].y == _p.y - 1))
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_boss.sh[i].x = 0;
			}
	}																// boss / shoot
	for (int i = 0; i < _nbShoot; i++)
		if (_sh[i].x == _boss.x && _sh[i].y == _boss.y + 5)
		{
			score += 1;
			_boss.life--;
			_sh[i].x = 0;
		}
	return false;
}

bool			Ft_retro::collision(void)
{
	int 	i = 0;
	if (_p.y == 1 || _p.y == maxheight - 3)
		return true;
	while (i < _nbStone)
	{
		for (int j = 0; j < 6; j++)
			if (_s[i].x == _p.x + j && _s[i].y == _p.y)			//collision player / stone
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_s[i].x = 0;
			}
		for (int j = 2; j < 4; j++)
			if (_s[i].x == _p.x + j &&
				(_s[i].y == _p.y - 1 || _s[i].y == _p.y + 1))	// player sides / stone
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_s[i].x = 0;
			}
		for (int j = 0; j < _nbShoot; j++)
			if (_s[i].x == _sh[j].x && _s[i].y == _sh[j].y)		//collision shoot / stone
			{
				mvprintw(_s[i].y, _s[i].x, " ");
				_sh[j].x = 0;
			}
		for (int j = 0; j < _nbBigStone; j++)
			for (int k = 0; k < 3; k++)
				if (_s[i].x == _bigS[j].x + k && _s[i].y == _bigS[j].y)		//collision bigS / stone
				{
					mvprintw(_s[i].y, _s[i].x, " ");
					_s[i].x = 0;
				}
		i++;
	}
	i = 0;
	while (i < _nbEnemy)
	{
		for (int j = 0; j < _nbBigStone; j++)
			for (int k = 0; k < 3; k++)
				if (_e[i].x == _bigS[j].x + k && _e[i].y == _bigS[j].y) //collision bigS / enemy
					_e[i].x = 0;
		for (int j = 0; j < 6; j++)
		{
			if (_e[i].x == _p.x + j && _e[i].y == _p.y) 		//collision player / enemy
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_e[i].x = 0;
			}
			if (_e[i].sh.x == _p.x + j && _e[i].sh.y == _p.y) 	//collision player / shoot enemy
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_e[i].sh.x = 0;
			}
		}
		for (int j = 2; j < 4; j++)
		{
			if (_e[i].x == _p.x + j &&
				(_e[i].y == _p.y - 1 || _e[i].y == _p.y + 1)) 		//player sides / enemy
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_e[i].x = 0;
			}
			if (_e[i].sh.x == _p.x + j &&
				(_e[i].sh.y == _p.y - 1 || _e[i].sh.y == _p.y + 1))	//player sides / shoot enemy
			{
				if (_p.life == 1)
					return true;
				_p.life -= 1;
				_e[i].sh.x = 0;
			}
		}
		for (int j = 0; j < _nbShoot; j++)
			if (_e[i].x != 0 && _sh[j].x != 0 &&
				_e[i].x == _sh[j].x + 1 && _e[i].y == _sh[j].y) 		//collision enemy / shoot
			{
				mvprintw(_sh[j].y, _sh[j].x, "  ");
				_sh[j].x = 0;
				_e[i].x = 0;
				score += 10;
				if (score % 100 == 0)
					_lvl++;
			}
		for (int j = 0; j < _nbEnemy; j++)
		{
			if (_e[j].sh.x != 0 &&
				_e[j].sh.x == _e[i].x && _e[j].sh.y == _e[i].y)			//collision enemy / shoot enemy
			{
				mvprintw(_e[i].y, _e[i].x, " ");
				_e[j].sh.x = 0;
				_e[i].x = 0;
			}
			if (_e[j].x != 0 && j != i &&
				_e[j].x == _e[i].x && _e[j].y == _e[i].y)		//collision enemy / enemy
			{
				mvprintw(_e[i].y, _e[i].x, " ");
				_e[j].x = 0;
				_e[i].x = 0;
			}
		}
		for (int j = 0; j < _nbStone; j++)
		{
			if (_e[i].x == _s[j].x && _e[i].y == _s[j].y) 		//collision stone / enemy
				_e[i].x = 0;
			if (_e[i].sh.x == _s[j].x && _e[i].sh.y == _s[j].y) //collision stone / shoot enemy
				_e[i].sh.x = 0;
		}
		if (_e[i].y == 0 || _e[i].y >= maxheight - 2)			//collision enemy / up||down screen
		{
			_e[i].x = 0;
			mvprintw(_e[i].y, _e[i].x, " ");
		}
		i++;
	}
	i = 0;
	while (i < _nbBigStone)
	{
		for (int j = 0; j < _nbBigStone; j++)
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++)
					if (_bigS[j].x != 0 && j != i &&
						_bigS[j].x + k == _bigS[i].x + l &&
						_sh[j].y == _bigS[i].y)						//collision bigS / bigS
					{
						mvprintw(_bigS[j].y, _bigS[j].x, " ");
						_bigS[j].x = 0;
					}
		for (int j = 0; j < _nbShoot; j++)
			for (int k = 0; k < 3; k++)
				if (_sh[j].x != 0 &&
					_sh[j].x == _bigS[i].x + k && _sh[j].y == _bigS[i].y)	//collision bigS / shoot
				{
					mvprintw(_sh[j].y, _sh[j].x, " ");
					_sh[j].x = 0;
				}
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 3; k++)
			if (_bigS[i].x + k == _p.x + j && _bigS[i].y == _p.y) 		//collision bigS / player
			{
				_p.life = 0;
				return true;
			}
		for (int j = 2; j < 4; j++)
			for (int k = 0; k < 3; k++)
				if (_bigS[i].x + k == _p.x + j &&
					(_bigS[i].y == _p.y - 1 || _bigS[i].y == _p.y + 1))	//collision bigS / player sides
				{
					_p.life = 0;
					return true;
				}
		for (int j = 0; j < _nbEnemy; j++)
			for (int k = 0; k < 3; k++)
				if (_e[j].sh.x != 0 &&
					_e[j].sh.x == _bigS[i].x + k && _e[j].sh.y == _bigS[i].y)//collision bigS / shoot enemy
				{
					mvprintw(_e[j].sh.y, _e[j].sh.x, " ");
					_e[j].sh.x = 0;
				}
		i++;
	}
	return false;
}
