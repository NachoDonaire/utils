#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class ATarget {
	protected:
		std::string type;
		ATarget();
		ATarget(const ATarget &w) { this->type = w.getType();};
		ATarget	&operator=(const ATarget &w){if (this != &w){this->type = w.getType();}return *this;};
	public:
		ATarget(std::string n, std::string t) : type(n), effects(t){};
		ATarget	*clone() const = 0;
		~ATarget(){};
		std::string getType() const {return this->type;};
		std::string getEffects() const {return this->effects;};
};




#endif
