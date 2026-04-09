#pragma once

#include <iostream>

/*
	When working with inheritance, private members need to
	be set to protected instead! Private members are invisible
	to inheriting classes.

	!virtual keyword tells compiler to check the exact subclass of
	!an object pointed to by a base class pointer. Without it,
	!calling a function by a base class pointer will default to
	!the base class function. With it, the compiler will check
	!the actual specific sub class and call the correct function
	!virtual should be paired with override!
	virtual void	attack(const std::string& target); <-parent class
	void	attack(const std::string& target) override; <-child class

	!destructors should always be virtual, otherwise child objects
	!will be incompletely deleted if using base class pointers
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
	virtual ~ClapTrap();

	//Parametrized constructor
	ClapTrap(std::string name);

	//Member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
