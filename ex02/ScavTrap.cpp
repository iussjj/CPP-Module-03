#include "ScavTrap.hpp"
#include <iostream>

/*
	CONSTRUCTOR CHAINING:
	Because ScavTrap is a child class of ClapTrap, a ScavTrap
	can't be constructed without constructing a ClapTrap first!

	When creating a ScavTrap like so: ScavTrap defaultRobot;
	1. compiler looks at ScavTrap
	2. sees it inherits from ClapTrap
	3. pause ScavTrap, runs ClapTrap() default constructor
	4. run ScavTrap() constructor

	To create a named ScavTrap, chain the parametrized constructor
	to the equivalent constructor of its parent:
	ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
	{
	
	}
	NOTE! The parameter names must match

	Function implementations can also be chained:
	void ScavTrap::attack(const std::string& target)
	{
		ClapTrap::attack(target); 
		this->_energyPoints--;
	}
	!BUT SHOULDN'T BE IN THIS CASE!
*/

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor called!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

/*
	Thanks to Object Slicing, the parent class copy constructor
	copies only the parts that also belong to the parent class,
	while ignoring the parts unique to the child.
	The parent copy constructor runs before the child copy constructor
	body { }
	Class members unique to the child class need to be handled manually.
*/

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	//function contents inherited from ClapTrap copy constructor
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &source)
{
	std::cout << "ScavTrap copy assignment operator called!" << std::endl;
	if (this != &source)
	{
		ClapTrap::operator=(source);
	}
	return *this;
}

ScavTrap::~ScavTrap() //no initialization list needed!
{
	std::cout	<< "ScavTrap " << this->_name
				<< " destroyed!" << std::endl;
	//after this destructor runs, the parent destructor runs automatically
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout	<< "ScavTrap " << name
				<< " created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
void	ScavTrap::attack(const std::string& target)
{
	if (this->_canAct("ScavTrap", "attack"))
	{
		this->_energyPoints--;
		std::cout 	<< "ScavTrap " << this->_name
					<< " attacks " << target
					<< " causing " << this->_attackDamage
					<< " points of damage!\n" 
					<< "It now has " << this->_energyPoints
					<< " energy points remaining." << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_canAct("ScavTrap", "enter Gate keeper mode"))
	{
		std::cout 	<< "ScavTrap " << this->_name
			<< " enters Gate keeper mode."
			<< std::endl;
	}
}

