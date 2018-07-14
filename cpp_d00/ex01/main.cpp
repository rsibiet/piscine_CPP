/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:04:56 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/26 13:04:57 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

int		add_info(Contact *c, std::string tmp, int i)
{
	std::string	buff;

	std::cout << tmp;
	if (!std::getline(std::cin, buff))
		return 1;
	while (buff.empty())
	{
		std::cout << tmp;
		if (!std::getline(std::cin, buff))
			return 1;
	}
	if (i == 0)
		c->first_name = buff;
	 else if (i == 1)
		c->last_name = buff;
	 else if (i == 2)
		c->nickname = buff;
	 else if (i == 3)
		c->login = buff;
	 else if (i == 4)
		c->address = buff;
	 else if (i == 5)
		c->email = buff;
	 else if (i == 6)
		c->phone_number = buff;
	 else if (i == 7)
		c->birthday = buff;
	 else if (i == 8)
		c->favorite_meal = buff;
	 else if (i == 9)
		c->underwear_color = buff;
	 else if (i == 10)
		c->darkest_secret = buff;
	return 0;
}

void	add_contact(Contact *c)
{
	if (add_info(c, "Enter your first name : ", 0) == 1 ||
	add_info(c, "Enter your last name : ", 1) == 1 ||
	add_info(c, "Enter your nickname : ", 2) == 1 ||
	add_info(c, "Enter your login : ", 3) == 1 ||
	add_info(c, "Enter your postal address : ", 4) == 1 ||
	add_info(c, "Enter your email address : ", 5) == 1 ||
	add_info(c, "Enter your phone number : ", 6) == 1 ||
	add_info(c, "Enter your birthday date : ", 7) == 1 ||
	add_info(c, "Enter your favorite_meal : ", 8) == 1 ||
	add_info(c, "Enter your underwear color : ", 9) == 1 ||
	add_info(c, "Enter your darkest_secret : ", 10) == 1)
		return ;
}

void	loop_dp(std::string s)
{
	int 	len = s.size();

	if (len > 9)
		std::cout << std::right << std::setw(10) << s.substr(0, 9).append(".");
	else
		std::cout << std::right << std::setw(10) << s;
}

int		dp_user_information(Contact c[8], int i)
{
	std::string	buff;

	std::cout << "Enter an index to display the contact's information." << std::endl;
	std::cout << ">> ";
	if (!std::getline(std::cin, buff))
		return 1;
	if (buff.size() > 1)
		return 1;
	std::string::const_iterator it = buff.begin();
	if (isdigit(*it) && (i = std::stoi(buff)) < 9 && i > 0 && !c[i - 1].first_name.empty())
	{
		i--;
		std::cout << "First_name: " << c[i].first_name << std::endl;
		std::cout << "Last_name: " << c[i].last_name << std::endl;
		std::cout << "Nickname: " << c[i].nickname << std::endl;
		std::cout << "Login: " << c[i].login << std::endl;
		std::cout << "Postal address: " << c[i].address << std::endl;
		std::cout << "Email address: " << c[i].email << std::endl;
		std::cout << "Phone number: " << c[i].phone_number << std::endl;
		std::cout << "Birthday date: " << c[i].birthday << std::endl;
		std::cout << "Favorite meal: " << c[i].favorite_meal << std::endl;
		std::cout << "Underwear color: " << c[i].underwear_color << std::endl;
		std::cout << "Darkest secret: " << c[i].darkest_secret << std::endl;
	}
	else
		return 1;
	return 0;
}

void	display_phonebook(Contact c[8])
{
	int		i = 0;

	if (!c[i].first_name.empty())
		std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	else
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	while (i < 8)
	{
		if (!c[i].first_name.empty())
		{
			std::cout << "         " << i + 1 << "|";
			loop_dp(c[i].first_name);
			std::cout << "|";
			loop_dp(c[i].last_name);
			std::cout << "|";
			loop_dp(c[i].nickname);
			std::cout << std::endl;
		}
		i++;
	}
	while (dp_user_information(c, 0) == 1)
		std::cout << "Error. Try again..." << std::endl;
}

int		new_contact(Contact *c, int i)
{
	if (i == 8)
	{
		std::cout << "PhoneBook full. ";
		std::cout << "You cant add anymore contact" << std::endl;
		std::cout << "Command available: \"SEARCH\"" << std::endl;
		return (-1);
	}
	add_contact(c);
	return (0);
}

int		main(void)
{
	Contact 	contact[8];
	int			i = 0;

	std::string	buff;
	while (buff != "EXIT")
	{
		if (buff != "EXIT")
			std::cout << "Enter a new command : ";
		if (std::cin.fail() || !std::getline(std::cin, buff))
			return 0;
		if (buff == "ADD" && new_contact(&contact[i], i) == 0)
			i++;
		else if (buff == "SEARCH")
			display_phonebook(contact);
		else if (buff != "EXIT" && i < 8)
			std::cout << "Commands available: \"ADD\" or \"SEARCH\"" << std::endl;
	}
	return (0);
}

