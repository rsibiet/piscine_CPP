/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:51:46 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/29 17:51:47 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		memoryLeak()
{
	std::string*		panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}