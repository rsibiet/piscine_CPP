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
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int			main(void)
{
	FragTrap kab("\033[32mKABTRAP\033[0m");
	ClapTrap clap("\033[32mCLAPTRAP\033[0m");
	ScavTrap usul("\033[33mUSUL\033[0m");
	NinjaTrap ninja("\033[34mNINJA\033[0m");
	NinjaTrap ninja2("\033[34mNINJA2\033[0m");
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
	std::cout << usul.name << " -> Hit points: " << usul.hitPts << std::endl;
	usul.takeDamage(30);
	std::cout << usul.name << " -> Hit points: " << usul.hitPts << std::endl;
	usul.takeDamage(90);
	std::cout << usul.name << " -> Hit points: " << usul.hitPts << std::endl;
	usul.beRepaired(20);
	std::cout << usul.name << " -> Hit points: " << usul.hitPts << std::endl;
	usul.beRepaired(95);
	std::cout << usul.name << " -> Hit points: " << usul.hitPts << std::endl;

	std::cout << std::endl;
	std::cout << "\033[32m*********************************************\033[0m";
	std::cout << std::endl << std::endl;

	ninja.ninjaShoebox(kab);
	ninja.ninjaShoebox(usul);
	ninja.ninjaShoebox(ninja2);
	ninja.ninjaShoebox(clap);
	ninja.rangedAttack(str);
	ninja.meleeAttack(str);
	std::cout << ninja.name << " -> Hit points: " << ninja.hitPts << std::endl;
	ninja.takeDamage(30);
	std::cout << ninja.name << " -> Hit points: " << ninja.hitPts << std::endl;
	ninja.takeDamage(90);
	std::cout << ninja.name << " -> Hit points: " << ninja.hitPts << std::endl;
	ninja.beRepaired(20);
	std::cout << ninja.name << " -> Hit points: " << ninja.hitPts << std::endl;
	ninja.beRepaired(95);
	std::cout << ninja.name << " -> Hit points: " << ninja.hitPts << std::endl;

	return (0);
}
