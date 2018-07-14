/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:45:30 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 15:45:43 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
#include <sstream>

class Brain {

public:

	int				weigth;
	int				nbNeuron;
	std::string		addr;

	Brain(void);
	std::string		identify(void);

};

#endif