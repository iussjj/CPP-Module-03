#include "FragTrap.hpp"
#include <iostream>

/*
	CONSTRUCTOR CHAINING:
	Because FragTrap is a child class of ClapTrap, a FragTrap
	can't be constructed without constructing a ClapTrap first!

	When creating a FragTrap like so: FragTrap defaultRobot;
	1. compiler looks at FragTrap
	2. sees it inherits from ClapTrap
	3. pause FragTrap, runs ClapTrap() default constructor
	4. run FragTrap() constructor

	To create a named FragTrap, chain the parametrized constructor
	to the equivalent constructor of its parent:
	FragTrap::FragTrap(std::string name) : ClapTrap(name)
	{
	
	}
	NOTE! The parameter names must match

	Function implementations can also be chained:
	void FragTrap::attack(const std::string& target)
	{
		ClapTrap::attack(target); 
		this->_energyPoints--;
	}
	!BUT SHOULDN'T BE IN THIS CASE!
*/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

/*
	Thanks to Object Slicing, the parent class copy constructor
	copies only the parts that also belong to the parent class,
	while ignoring the parts unique to the child.
	The parent copy constructor runs before the child copy constructor
	body { }
	Class members unique to the child class need to be handled manually.
*/

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	//function contents inherited from ClapTrap copy constructor
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &source)
{
	std::cout << "FragTrap copy assignment operator called!" << std::endl;
	if (this != &source)
	{
		ClapTrap::operator=(source);
	}
	return *this;
}

FragTrap::~FragTrap() //no initialization list needed!
{
	std::cout	<< "FragTrap " << this->_name
				<< " destroyed!" << std::endl;
	//after this destructor runs, the parent destructor runs automatically
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout	<< "FragTrap " << name
				<< " created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_canAct("FragTrap", "request high-fives from the guys"))
	{
		std::cout 	<< "FragTrap " << this->_name
			<< " excitedly requests high-fives from the guys ✋."
			<< std::endl;
	}
}

