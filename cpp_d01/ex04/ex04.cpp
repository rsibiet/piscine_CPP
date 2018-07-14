/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:30:52 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 15:30:56 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	const char			*brain = "HI THIS IS BRAIN";
	const char			*brainPtr = brain;
	const char			&brainRef = *brain;

	std::cout << brainPtr << std::endl;
	std::cout << &brainRef << std::endl;

	return (0);
}