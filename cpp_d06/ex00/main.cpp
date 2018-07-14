/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:10:44 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/07 10:10:46 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctype.h>
#include <float.h>
#include <cmath>
#include <ctype.h>

static void		isDouble(float i)
{
	if (i <= INT_MAX && isprint(i) != 0)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	if (i > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else if (fmod(i, 1) == 0)
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	if (fmod(i, 1) == 0)
		std::cout << "double: " << i << ".0" << std::endl;
	else
		std::cout << "double: " << i << std::endl;
}

static void		isFloat(float i)
{
	if (i <= INT_MAX && isprint(i) != 0)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	if (fmod(i, 1) == 0)
	{
		std::cout << "float: " << i << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << i << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}
}

static void		isInt(int i)
{
	if (isprint(i) != 0)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void		isOther(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void		isInf(std::string str)
{
	char sign = '+';
	if (str == "-inff" || str == "-inf")
		sign = '-';
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << sign << "inff" << std::endl;
	std::cout << "double: " << sign << "inf" << std::endl;
}

static void		isNan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void		isChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c)  << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c)  << ".0" << std::endl;
}

static void		tryToConvert(std::string str)
{
	int i = 1;
	bool intVal = false;
	bool floatVal = false;
	bool doubleVal = false;

	if (str[0] == '+' || str[0] == '-' || isdigit(str[0]) != 0)
	{
		while (str[i] != '\0' && isdigit(str[i]) != 0)
			i++;
		if (str[i] == '\0' && isdigit(str[i - 1]) != 0)
			intVal = true;
		else if (str[i] == '.')
		{
			i++;
			while (str[i] != '\0' && isdigit(str[i]) != 0)
				i++;
			if (str[i] == '\0' && isdigit(str[i - 1]) != 0)
				doubleVal = true;
			else if (str[i] == 'f' && str[i + 1] == '\0' && isdigit(str[i - 1]) != 0)
				floatVal = true;
		}
	}
	std::string::size_type sz;   // alias of size_t

	if (str.length() == 1 && isdigit(str[0]) == 0)
		isChar(static_cast<char>(str[0]));
	else if (str == "nan" || str == "nanf")
		isNan();
	else if (str == "-inff" || str == "-inf" || str == "+inff"
							|| str == "+inf")
		isInf(str);
	else if(intVal == true && std::stoll(str.c_str(), &sz) <= INT_MAX
									&& std::stoll(str.c_str(), &sz) >= INT_MIN)
		isInt(static_cast<int>(std::stoi(str.c_str(), &sz)));
	else if(floatVal == true && std::stof(str.c_str(), &sz) <= FLT_MAX
									  && std::stof(str.c_str(), &sz) >= -FLT_MAX)
		isFloat(static_cast<float>(std::stof(str.c_str(), &sz)));
	else if(doubleVal == true && std::stod(str.c_str(), &sz) <= DBL_MAX
									   && std::stod(str.c_str(), &sz) >= -DBL_MAX)
		isDouble(static_cast<double>(std::stod(str.c_str(), &sz)));
	else
		isOther();
}

int			main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "This program takes an argument following a scalar types: ";
		std::cout << "char, int, float or double." << std::endl;
		return 0;
	}
	if (ac > 2)
	{
		std::cout << "This program takes only one argument." << std::endl;
		return 0;
	}
	tryToConvert(static_cast<std::string>(av[1]));

	return 0;
}