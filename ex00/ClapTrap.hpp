#pragma once

#include <iostream>

/*
	Note: Even though _name and _attackDamage don't need
	to be mutable, making them const will break the copy
	assignment operator!
*/

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	bool		_canAct(std::string action) const;

public:
	//Orthodox Canonical Form
	ClapTrap();
	ClapTrap(const ClapTrap &source);
	ClapTrap &operator=(const ClapTrap &source);
	~ClapTrap();

	//Parametrized constructor
	ClapTrap(std::string name);

	//Member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
