#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nConstructor tests:" << std::endl;

	ClapTrap beelzebub("Beelzebub");
	ClapTrap defaultTrap; 
	ClapTrap beelzebubClone(beelzebub); 

	std::cout << "\nAction tests:" << std::endl;

	beelzebub.attack("some poor bastard");
	beelzebub.takeDamage(5);
	beelzebub.beRepaired(3);

	std::cout << "\nOut of energy test:" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		beelzebub.attack("a dead horse");
	}

	beelzebub.attack("an even deader horse");
	beelzebub.beRepaired(5);

	std::cout << "\nDeath test" << std::endl;
	beelzebubClone.takeDamage(50);
	beelzebubClone.attack("Beelzebub");
	beelzebubClone.beRepaired(10);

	std::cout << "\nDestructor test" << std::endl;
	return 0;
}