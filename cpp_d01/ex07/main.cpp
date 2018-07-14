/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:13:29 by rsibiet           #+#    #+#             */
/*   Updated: 2017/06/12 17:13:30 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

void		replaceInFile(char **av)
{
	std::ofstream 	replacefile;
	std::string 	line;
	std::string 	ss = av[1];
	char			*s = new char[ss.length() + 8];

	ss.append(".replace");
	std::strcpy(s, ss.c_str());
	std::ifstream myfile (av[1]);
	if (myfile.is_open())
	{
		FILE *fp = fopen(s, "w");
		if (!fp)
		{
    		std::cout << "Failed to create " << ss << " file." << std::endl;
    		return ;
		}
		fclose (fp);
		replacefile.open (s);

    	while (std::getline(myfile,line))
    	{
    		line = ReplaceAll(line, av[2], av[3]);
			replacefile << line << std::endl;
		}
		replacefile.close();
		myfile.close();
	}
	else
		std::cout << "Unable to open file." << std::endl;
	delete[] s;
}

int			main(int ac, char **av)
{
	if (ac == 4)
		replaceInFile(av);
	else
		std::cout << "replace program need 3 arguments." << std::endl;
	return 0;
}