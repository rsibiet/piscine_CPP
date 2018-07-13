/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigStone.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:51:15 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:21:19 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGSTONE_CLASS_HPP
# define BIGSTONE_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Entity.class.hpp"

class BigStone : public Entity
{

public:

	BigStone(void);
	BigStone(BigStone const & src);
	virtual ~BigStone(void);

	BigStone				&operator=(BigStone const & rhs);

	int						x, y;
	void					moveBigStone(clock_t startTime, int lvl);
	void					dpBigStone(void);

private:

	double					_time, _time2;
	int						_maxwidth, _maxheight;

};

#endif
