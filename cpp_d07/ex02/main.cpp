/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:15:21 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/21 10:15:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int			main(void)
{
	int		tabA[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	double	tabB[] = {8.21, 16.42, 32.84, 64.168, 128.336};
	Array 	<int>A(10);
	Array 	<double>B(5);

	std::cout << "---------------tabA---------------------" << std::endl;
	std::cout << "tabA[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}" << std::endl;
	std::cout << "A.size(): " << A.size() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			A[i] = tabA[i];
			std::cout << "Index: " << i << ", value: " << A[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Index: " << i << " -> "<< e.what() << std::endl;
		}
	}

	std::cout << std::endl << "---------------tabB---------------------" << std::endl;
	std::cout << "tabB[] = {8.21, 16.42, 32.84, 64.168, 128.336}" << std::endl;
	std::cout << "B.size(): " << B.size() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			B[i] = tabB[i];
			std::cout << "Index: " << i << ", value: " << B[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Index: " << i << " -> "<< e.what() << std::endl;
		}
	}

	Array 	<int>C(A);
	int tmp;
	std::cout << std::endl << "---------------tabC---------------------" << std::endl;
	std::cout << "<int>C(A)" << std::endl;
	std::cout << "C.size(): " << B.size() << std::endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			tmp = C[i];
			std::cout << "Index: " << i << ", value: " << C[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Index: " << i << " -> "<< e.what() << std::endl;
		}
	}
	return 0;
}