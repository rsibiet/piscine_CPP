/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:04:49 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/26 11:04:55 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

void	str_to_up(int ac, char **s)
{
	int		i = 1;
	int		j = 0;

	while (i < ac)
	{
		while (s[i][j])
		{
			std::cout << (char)toupper(s[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	std::cout << std::endl;
}

int		main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		str_to_up(ac, av);
	return (0);
}