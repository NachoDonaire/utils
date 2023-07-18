#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class ScalarConverter
{
	private:
		char	c;
		int	i;
		float	f;
		double	d;

		bool	infinite;
		bool	isfloat;
		bool	nan;
		bool	nw;
 	public:
    		ScalarConverter();
    		ScalarConverter(const ScalarConverter &f);
    		~ScalarConverter();
    		ScalarConverter& operator=(const ScalarConverter &f);
		void			setChar(char t);
		void			setInt(int t);
		void			setFloat(float t);
		void			setDouble(double t);
		char			getChar() const;
		int			getInt() const;
		bool			getIsFloat() const;
		bool			getNaN() const;
		bool			getInfinite() const;
		float			getFloat() const;
		bool			getNw() const;
		double			getDouble() const;
		class	InvalidTypeException : public std::exception{
			virtual const char *what() const throw() { return "Invalid type for convert" ; };
		};
		void		convert(std::string str);
		int		isDigit(std::string &s);
};
std::ostream &operator<<(std::ostream &os, const ScalarConverter &s);
#endif
