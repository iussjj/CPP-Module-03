#pragma once

#include "ClapTrap.hpp"

/*
	[ class FragTrap ] - child class
	[ : ] - inherits from
	[ public ] - access specifier: everything with protected/public
	access in parent class has the same access in the child class too
	[ class to inherit ]

	without public access specifier, inherited public member functions
	from ClapTrap would become private (the default)
*/

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap &source);
	FragTrap &operator=(const FragTrap &source);
	~FragTrap();

	FragTrap(std::string name);

	void	highFivesGuys(void);
};

/*
	NOTE! The subject requires FragTraps to print different constructor
	and destructor messages from the base ClapTrap. But UNLIKE the
	requirement for ScavTrap, there is no requirement for the attack
	function to do the same! Therefore we aren't overwriting the parent
	class function here. Also: DRY unless absolutely necessary.
*/