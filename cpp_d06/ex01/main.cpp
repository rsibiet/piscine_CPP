/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:25:56 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/08 11:25:58 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <climits>

struct Data
{
	std::string 	s1;
	int 			n;
	std::string		s2;
};

static void		*serialize(void)
{
	const char 		lst[] = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
	std::string		s;
	int				len = strlen(lst) - 1;
	char			*ret = NULL;

	for(int i = 0; i < 8; i++)
		s.push_back(lst[rand() % len]);
	std::stringstream integer;
	integer << rand() % INT_MAX;
	s += integer.str();
	for(int i = 0; i < 8; i++)
		s.push_back(lst[rand() % len]);
	ret = const_cast<char *>(s.c_str());
	return (reinterpret_cast<void *>(ret));
}

static Data		*deserialize(void *raw)
{
	Data			*dt = new Data;
	char			*s = reinterpret_cast<char *>(raw);
	std::string		stNb;
	std::string::size_type sz;
	int		len = strlen(s);
	int		i = 0;

	while (i < 8)
	{
		dt->s1.push_back(s[i]);
		len--;
		i++;
	}
	while (len > 8)
	{
		stNb.push_back(s[i]);
		len--;
		i++;
	}
	dt->n = stoi(stNb, &sz);
	while (len > 0)
	{
		dt->s2.push_back(s[i]);
		len--;
		i++;
	}
	return dt;
}

int				main (void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	void 	*s = serialize();
	Data	*dt;

	std::cout << std::endl << "Serialized data: ";
	std::cout << reinterpret_cast<char *>(s) << std::endl;
	std::cout << "address on the heap: " << s << std::endl;
	dt = deserialize(s);
	std::cout << std::endl << "deserialize:"<< std::endl;
	std::cout << "	- Data->s1: " << dt->s1 << std::endl;
	std::cout << "	- Data->n: " << dt->n << std::endl;
	std::cout << "	- Data->s2: " << dt->s2 << std::endl;
	delete dt;
	return 0;
}
