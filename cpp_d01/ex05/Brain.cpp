/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:45:24 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 15:45:26 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void): weigth(1800),
					nbNeuron(2000000000)
{
	const void * address = (void*)this;
	std::stringstream ss;
	ss << address;
	this->addr = ss.str();
	return ;
}

std::string		Brain::identify(void)
{
	return (this->addr);
}