#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nCLAPTRAP TESTS" << std::endl;
	ClapTrap og("Beelzebub");
	og.attack("a training dummy");

	std::cout << "\nSCAVTRAP CONSTRUCTOR SEQUENCE" << std::endl;
	ScavTrap alpha("Alpha");
	ScavTrap defaultScav;
	ScavTrap cloneScav(alpha);

	std::cout << "\nSCAVTRAP ACTIONS & OVERRIDES" << std::endl;
	alpha.attack("an unfortunate bandit");
	alpha.takeDamage(25);
	alpha.beRepaired(10);
	alpha.guardGate();

	std::cout << "\nFRAGTRAP CONSTRUCTOR SEQUENCE" << std::endl;
	// Watch the terminal: it should print ClapTrap constructor, THEN FragTrap constructor!
	FragTrap chad("Chad");
	FragTrap defaultFrag;
	FragTrap cloneFrag(chad);

	std::cout << "\nFRAGTRAP ACTIONS & INHERITANCE" << std::endl;
	// Because we DID NOT override attack(), this should print the ClapTrap message,
	// BUT it should deal exactly 30 damage, proving the stats updated correctly!
	chad.attack("a terrifying badass");
	
	// Inherited functions
	chad.takeDamage(50);
	chad.beRepaired(25);

	std::cout << "\nFRAGTRAP SPECIAL ABILITY" << std::endl;
	chad.highFivesGuys();

	std::cout << "\nDEATH AND DENIAL TESTS" << std::endl;
	std::cout << "--- Killing ScavTrap Clone ---" << std::endl;
	cloneScav.takeDamage(150);
	cloneScav.guardGate();

	std::cout << "\n--- Killing FragTrap Clone ---" << std::endl;
	cloneFrag.takeDamage(150);
	cloneFrag.attack("the air");
	cloneFrag.highFivesGuys();

	std::cout << "\nDESTRUCTOR SEQUENCE" << std::endl;
	// The child destructors (ScavTrap/FragTrap) MUST fire 
	// before their respective parent (ClapTrap) destructors!
	return 0;
}