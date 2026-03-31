#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n========== CLAPTRAP TESTS (Ensuring base still works) ==========" << std::endl;
	ClapTrap og("Beelzebub");
	og.attack("a training dummy");

	std::cout << "\n========== SCAVTRAP CONSTRUCTOR CHAINING ==========" << std::endl;
	ScavTrap alpha("Alpha");
	ScavTrap defaultScav;
	ScavTrap cloneScav(alpha);

	std::cout << "\n========== SCAVTRAP ACTIONS & OVERRIDES ==========" << std::endl;
	alpha.attack("an unfortunate bandit");
	alpha.takeDamage(25);
	alpha.beRepaired(10);
	alpha.guardGate();

	std::cout << "\n========== FRAGTRAP CONSTRUCTOR CHAINING ==========" << std::endl;
	// Watch the terminal: it should print ClapTrap constructor, THEN FragTrap constructor!
	FragTrap chad("Chad");
	FragTrap defaultFrag;
	FragTrap cloneFrag(chad);

	std::cout << "\n========== FRAGTRAP ACTIONS & INHERITANCE ==========" << std::endl;
	// Because we DID NOT override attack(), this should print the ClapTrap message,
	// BUT it should deal exactly 30 damage, proving the stats updated correctly!
	chad.attack("a terrifying badass");
	
	// Inherited functions
	chad.takeDamage(50);
	chad.beRepaired(25);

	std::cout << "\n========== FRAGTRAP SPECIAL ABILITY ==========" << std::endl;
	chad.highFivesGuys();

	std::cout << "\n========== DEATH AND DENIAL TESTS ==========" << std::endl;
	std::cout << "--- Killing ScavTrap Clone ---" << std::endl;
	cloneScav.takeDamage(150);
	cloneScav.guardGate();

	std::cout << "\n--- Killing FragTrap Clone ---" << std::endl;
	cloneFrag.takeDamage(150);
	cloneFrag.attack("the air");
	cloneFrag.highFivesGuys();

	std::cout << "\n========== DESTRUCTOR CHAINING ==========" << std::endl;
	// The child destructors (ScavTrap/FragTrap) MUST fire 
	// before their respective parent (ClapTrap) destructors!
	return 0;
}