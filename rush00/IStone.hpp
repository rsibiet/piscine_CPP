/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IStone.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <avella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:10:56 by avella            #+#    #+#             */
/*   Updated: 2017/06/18 15:18:38 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTONE_HPP
# define ISTONE_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>

class IStone{

public:
    virtual ~IStone() {}
    virtual void					moveStone(clock_t startTime, int lvl) = 0;
  	virtual void					dpStone(void) = 0;
};

#endif
