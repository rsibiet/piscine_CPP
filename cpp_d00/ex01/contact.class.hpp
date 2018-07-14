/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:45:10 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/26 15:45:12 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{

public:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string address;
	std::string email;
	std::string phone_number;
	std::string birthday;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;

	Contact(void);
	~Contact(void);

};

#endif