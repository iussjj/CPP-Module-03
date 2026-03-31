#pragma once

#include "ClapTrap.hpp"

/*
	[ class ScavTrap ] - child class
	[ : ] - inherits from
	[ public ] - access specifier: everything with protected/public
	access in parent class has the same access in the child class too
	[ class to inherit ]

	without public access specifier, inherited public member functions
	from ClapTrap would become private (the default)
*/

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap &source);
	ScavTrap &operator=(const ScavTrap &source);
	~ScavTrap();

	ScavTrap(std::string name);

	void	attack(const std::string& target);
	void	guardGate(void);
};