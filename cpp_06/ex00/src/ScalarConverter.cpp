#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter()
{
	this->c = 0;
	this->i = 0;
	this->f = 0;
	this->d = 0;
	this->infinite = 0;
	this->isfloat = 0;
	this->nw = 0;
	this->nan = 0;
        std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{
	(void)a;
}

ScalarConverter::~ScalarConverter()
{
        std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &f)
{
        if (this != &f)
        {
        	return *this;
        }
        return *this;
}

int	ScalarConverter::isDigit(std::string& s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			i++;
		else
		{
			if (std::isdigit(s[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

void	ScalarConverter::setChar(char t)
{
	this->c = t;
}
void	ScalarConverter::setInt(int t)
{
	this->i = t;
}
void	ScalarConverter::setFloat(float t)
{
	this->f = t;
}
void	ScalarConverter::setDouble(double t)
{
	this->d = t;
}

char	ScalarConverter::getChar() const
{
	return this->c;
}

int	ScalarConverter::getInt() const 
{
	return this->i;
}

bool	ScalarConverter::getNw() const
{
	return this->nw;
}

float	ScalarConverter::getFloat() const
{
	return this->f;
}

double	ScalarConverter::getDouble() const
{
	return this->d;
}

bool ScalarConverter::getIsFloat() const
{
	return this->isfloat;
}

bool ScalarConverter::getInfinite() const
{
	return this->infinite;
}

bool ScalarConverter::getNaN() const
{
	return this->nan;
}

void	ScalarConverter::convert(std::string str)
{
	try{
		if (str == "nanf" || str == "nan" || str == "inf")
		{
			this->nan = 1;
			this->infinite = 1;
			return ;
		}
		if (ScalarConverter::isDigit(str))
		{
			if (str.find('.') != std::string::npos)
			{
				this->isfloat = 1;
				setChar(static_cast<char>(std::atof(str.c_str())));
				setInt(static_cast<int>(std::atof(str.c_str())));
				setFloat(static_cast<float>(std::atof(str.c_str())));
				setDouble(static_cast<double>(std::atof(str.c_str())));
			}
			else
			{
				setChar(static_cast<char>(std::atoi(str.c_str())));
				setInt(static_cast<int>(std::atoi(str.c_str())));
				setFloat(static_cast<float>(std::atoi(str.c_str())));
				setDouble(static_cast<double>(std::atoi(str.c_str())));
			}

		}
		else if (str.size() == 1)
		{
				setChar(static_cast<char>(str[0]));
				setInt(static_cast<int>(str[0]));
				setFloat(static_cast<float>(str[0]));
				setDouble(static_cast<double>(str[0]));
		}
		else
		{
			this->nw = 1;
			throw ScalarConverter::InvalidTypeException();
		}
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, const ScalarConverter &s)
{
	if (s.getNw() == 1)
	{
		os << "No valid input" << std::endl;
		return os;
	}
	if (s.getIsFloat() == 1)
		os << "char : Non displayable" << std::endl;
	else if (s.getInfinite() == 1 || s.getNaN() == 1)
		os << "char : Impossible" << std::endl;
	else
		os << "char : " << s.getChar() << std::endl;
	if (s.getInfinite() == 1 || s.getNaN() == 1)
	{
		os << "int : " << "nan"  << std::endl;
		os << "float : " << "nan" << std::endl;
		os << "double : " << "nan";
		return os;
	}
	os << "int : " << s.getInt() << std::endl;
	os << "float : " << s.getFloat() << std::endl;
	os << "double : " << s.getDouble();

	return os;
}
