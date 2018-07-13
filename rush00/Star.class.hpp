/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:00:45 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 16:16:12 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_CLASS_HPP
# define STAR_CLASS_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Entity.class.hpp"
#include "IStar.hpp"

class Star : public Entity, public IStar
{

public:

	Star(void);
	Star(Star const & rhs);
	virtual ~Star(void);

	Star					&operator=(Star const & rhs);

	int			x, y;
	void		moveStar(clock_t StartTime, int lvl);
	void		dpStar(void);

private:

	double					_time;
	int						_maxwidth, _maxheight;

};

#endif
