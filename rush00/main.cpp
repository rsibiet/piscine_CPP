/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:16:35 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/17 18:45:37 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_retro.class.hpp"

int				main(void)
{
	int ret = 1, maxheight, maxwidth;
	initscr();
	getmaxyx(stdscr, maxheight, maxwidth);

	if (maxheight < MAXH || maxwidth < MAXW)
	{
		clear();
		endwin();
		std::cout << "Window too small to start the game." << std::endl;
		return 0;
	}
	while (ret == 1)
	{
		Ft_retro	*r = new Ft_retro();
		ret = r->start();
		delete r;
	}
	return 0;
}
