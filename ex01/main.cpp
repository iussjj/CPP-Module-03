#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n========== CLAPTRAP TESTS (Ensuring base still works) ==========" << std::endl;
	ClapTrap og("Beelzebub");
	og.attack("a training dummy");

	std::cout << "\n========== SCAVTRAP CONSTRUCTOR CHAINING ==========" << std::endl;
	// Watch the terminal here: it should print the ClapTrap constructor, THEN the ScavTrap constructor!
	ScavTrap alpha("Alpha");
	ScavTrap defaultScav;
	ScavTrap cloneScav(alpha);

	std::cout << "\n========== SCAVTRAP ACTIONS & OVERRIDES ==========" << std::endl;
	// Should use the OVERRIDDEN attack function (ScavTrap message, 20 damage)
	alpha.attack("an unfortunate bandit");
	
	// Should use the INHERITED takeDamage and beRepaired functions
	alpha.takeDamage(25);
	alpha.beRepaired(10);

	std::cout << "\n========== SCAVTRAP SPECIAL ABILITY ==========" << std::endl;
	alpha.guardGate();

	std::cout << "\n========== DEATH AND DENIAL TEST ==========" << std::endl;
	// Let's kill the clone to make sure the inherited _canAct perfectly stops the special ability
	cloneScav.takeDamage(150);
	cloneScav.attack("the air");
	cloneScav.guardGate();

	std::cout << "\n========== DESTRUCTOR CHAINING ==========" << std::endl;
	// Watch the terminal: ScavTrap destructors must fire BEFORE ClapTrap destructors!
	return 0;
}