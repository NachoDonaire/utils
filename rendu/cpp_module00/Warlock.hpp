#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(const Warlock &w) { this->name = w.getTitle() ; this->title = w.getTitle();};
		Warlock	&operator=(const Warlock &w){if (this != &w){this->name = w.getName(); this->title = w.getTitle();}return *this;};
	public:
		Warlock(std::string n, std::string t) : name(n), title(t){};
		~Warlock(){};
		std::string getName() const {return this->name;};
		std::string getTitle() const {return this->name;};
		void	    setTitle(const std::string &t) {if (title == t) {return ;} this->title = t;};
};




#endif
