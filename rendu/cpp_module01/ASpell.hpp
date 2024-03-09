#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class ASpell {
	protected:
		std::string name;
		std::string effects;
		ASpell();
		ASpell(const ASpell &w) { this->name = w.getName() ; this->effects = w.getEffects();};
		ASpell	&operator=(const ASpell &w){if (this != &w){this->name = w.getName(); this->effects = w.getTitle();}return *this;};
	public:
		ASpell(std::string n, std::string t) : name(n), effects(t){};
		ASpell	*clone() const = 0;
		~ASpell(){};
		std::string getName() const {return this->name;};
		std::string getEffects() const {return this->effects;};
};




#endif
