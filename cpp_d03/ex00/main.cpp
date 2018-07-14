/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:46:42 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/31 17:46:43 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int			main(void)
{
	FragTrap kab("\033[32mKABTRAP\033[0m");
	std::string const &str = "\033[31mATHENA\033[0m";
	srand((int)time(NULL));

	kab.rangedAttack(str);
	kab.meleeAttack(str);
	std::cout << " Energy points of " << kab.name << ": " \
	<< kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	std::cout << " Energy points of " << kab.name << ": " \
	<< kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	std::cout << " Energy points of " << kab.name << ": " \
	<< kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	kab.vaulthunter_dot_exe(str);
	kab.vaulthunter_dot_exe(str);
	std::cout << " Energy points of " << kab.name << ": " \
	<< kab.energyPts << std::endl;
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.takeDamage(30);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.takeDamage(90);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.beRepaired(20);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.beRepaired(110);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	return (0);
}
