#pragma once

#include <iostream>

/*
	When working with inheritance, private members need to
	be set to protected instead! Private members are invisible
	to inheriting classes.
*/

class ClapTrap
{
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
	bool		_canAct(std::string type, std::string action) const;

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
