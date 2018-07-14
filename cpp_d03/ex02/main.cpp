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
#include "ScavTrap.hpp"

int			main(void)
{
	FragTrap kab("\033[32mKABTRAP\033[0m");
	ScavTrap usul("\033[32mUSUL\033[0m");
	std::string const &str = "\033[31mATHENA\033[0m";
	srand((int)time(NULL));

	kab.rangedAttack(str);
	kab.meleeAttack(str);
	std::cout << kab.name << " -> Energy points: " << kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	std::cout << kab.name << " -> Energy points: " << kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	std::cout << kab.name << " -> Energy points: " << kab.energyPts << std::endl;
	kab.vaulthunter_dot_exe(str);
	kab.vaulthunter_dot_exe(str);
	kab.vaulthunter_dot_exe(str);
	std::cout << kab.name << " -> Energy points: " << kab.energyPts << std::endl;
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.takeDamage(30);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.takeDamage(90);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.beRepaired(20);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;
	kab.beRepaired(95);
	std::cout << kab.name << " -> Hit points: " << kab.hitPts << std::endl;

	std::cout << std::endl;
	std::cout << "\033[32m*********************************************\033[0m";
	std::cout << std::endl << std::endl;

	usul.challengeNewcomer();
	usul.challengeNewcomer();
	usul.challengeNewcomer();
	usul.challengeNewcomer();
	usul.challengeNewcomer();
	usul.rangedAttack(str);
	usul.meleeAttack(str);
	std::cout << usul.name << " -> hit points: " << usul.hitPts << std::endl;
	usul.takeDamage(30);
	std::cout << usul.name << " -> hit points: " << usul.hitPts << std::endl;
	usul.takeDamage(90);
	std::cout << usul.name << " -> hit points: " << usul.hitPts << std::endl;
	usul.beRepaired(20);
	std::cout << usul.name << " -> hit points: " << usul.hitPts << std::endl;
	usul.beRepaired(95);
	std::cout << usul.name << " -> hit points: " << usul.hitPts << std::endl;

	return (0);
}
