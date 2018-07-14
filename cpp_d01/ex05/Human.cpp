/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:45:51 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 15:45:52 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void): b(Brain())
{
	return ;
}

Human::~Human(void)
{
	return ;
}

const std::string		Human::identify(void)
{
	return (this->b.identify());
}

Brain					Human::getBrain(void)
{
	return (this->b);
}