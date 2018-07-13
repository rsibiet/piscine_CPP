/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stone.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:26:56 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:21:32 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STONE_CLASS_HPP
# define STONE_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Entity.class.hpp"
#include "IStone.hpp"

class Stone : public Entity, public IStone
{

public:

	Stone(void);
	Stone(Stone const & src);
	virtual ~Stone(void);

	Stone					&operator=(Stone const & rhs);

	int						x, y;
	virtual	void					moveStone(clock_t startTime, int lvl);
	virtual void					dpStone(void);

private:

	double					_time;
	int						_maxwidth, _maxheight;

};

#endif
