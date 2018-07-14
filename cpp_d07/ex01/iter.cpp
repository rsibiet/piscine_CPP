/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:25:34 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/08 16:25:35 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template < typename T >
void	ft_test(T const & s)
{
	std::cout << s << ", ";
}

template < typename ADDR >
void		iter(ADDR * array, int len, void (*f)(ADDR const &))
{
	int		i = 0;

	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

int			main(void)
{
	int				tabInt[] = {0, 42, 24, -1};
	char			s[] = "stringTest";
	std::string 	list[] = {"test00", "test01", "test02", "test03"};

	std::cout << std::endl << "test with int tab: " << std::endl;
	::iter(tabInt, 4, ft_test);
	std::cout << std::endl << std::endl;
	std::cout << "test with char tab: " << std::endl;
	::iter(s, strlen(s), ft_test);
	std::cout << std::endl << std::endl;
	std::cout << "test with string tab: " << std::endl;
	::iter(list, 4, ft_test);
	std::cout << std::endl << std::endl;
	return 0;
}