#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Anonymous";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_name = source._name;
		this->_hitPoints = source._hitPoints;
		this->_energyPoints = source._energyPoints;
		this->_attackDamage = source._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout	<< "ClapTrap " << this->_name
				<< " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout	<< "ClapTrap " << name
				<< " created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

bool	ClapTrap::_canAct(std::string action) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " is dead and can't "
					<< action << "!" << std::endl;
		return false;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " is out of energy and can't " 
					<< action << "!" << std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_canAct("attack"))
	{
		this->_energyPoints--;
		std::cout 	<< "ClapTrap " << this->_name
					<< " attacks " << target
					<< " causing " << this->_attackDamage
					<< " points of damage!\n" 
					<< "It now has " << this->_energyPoints
					<< " energy points remaining." << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)this->_hitPoints)
	{
		this->_hitPoints = 0;
	}
	else 
	{
		this->_hitPoints -= amount;
	}

	std::cout	<< "ClapTrap " << this->_name
				<< " takes " << amount
				<< " points of damage!\n" 
				<< "It now has " << this->_hitPoints
				<< " hit points remaining." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
		if (this->_canAct("be repaired"))
		{
			this->_energyPoints--;
			this->_hitPoints += amount;
			std::cout 	<< "ClapTrap " << this->_name
						<< " repairs itself and regains "
						<< amount << " hit points!\n"
						<< "Hit points now: " << this->_hitPoints << '\n'
						<< "Energy points now: " << this->_energyPoints
						<< std::endl;
		}
}
