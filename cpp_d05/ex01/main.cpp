/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:40:26 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/02 13:40:27 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	int		grade = -42;

	try
	{
		 Bureaucrat brt = Bureaucrat("hippo", 42);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	std::cout << "----- tests with grade between -42 and 300 -----" << std::endl;
	while (grade <= 180)
	{
		try
		{
			Bureaucrat brt = Bureaucrat("loop", grade);
		}
		catch (std::exception & e)
		{
			std::cout << "Exception catched: " << e.what();
			std::cout << ", Grade value: " << grade << std::endl;
		}
		grade++;
	}
	return (0);
}