/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:45:57 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/30 15:45:59 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H
#include "Brain.hpp"

class Human {

public:

	Brain		b;

	Human(void);
	~Human(void);
	const std::string	identify(void);
	Brain				getBrain(void);

};

#endif