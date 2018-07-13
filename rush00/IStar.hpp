/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IStar.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <avella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:10:50 by avella            #+#    #+#             */
/*   Updated: 2017/06/18 15:22:42 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTAR_HPP
# define ISTAR_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>

class IStar{

public:
    virtual ~IStar() {}
    virtual  void		moveStar(clock_t startTime, int lvl) = 0;
  	virtual void		dpStar(void) = 0;
};

#endif
