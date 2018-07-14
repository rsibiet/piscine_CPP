/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:44:35 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/29 16:44:36 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	 ponyOnTheHeap(void)
{
	Pony* 	heap_pony = new Pony("chupachups", "black", "white", 140, 190);
	heap_pony->makeSomeStuff(4, 20);
	delete heap_pony;
}

void	 ponyOnTheStack(void)
{
	Pony 	stack_pony = Pony("Chocamix", "pink", "yellow", 100, 140);
	stack_pony.makeSomeStuff(6, 15);
}

int		main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();

	return (0);
}