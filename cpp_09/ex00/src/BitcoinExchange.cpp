#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{
	this->fileName ="";
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	this->fileName = file;
	//this->csvFile(fileName, std::fstream::in);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a)
{
	this->fileName = a.fileName;
	//this->csvFile = a.csvFile;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &f)
{
        if (this != &f)
        {
		//	this->csvFile.close();
			this->fileName = f.fileName;
		///	this->csvFile(this->fileName, std::fstream::in);
        }
        return *this;
}

int	BitcoinExchange::errorManagement(int key)
{
	if (key == 0)
		std::cout << "Not enough arguments" << std::endl;
	return (0);
}

std::string BitcoinExchange::getFileName()
{
	return this->fileName;
}

int	BitcoinExchange::parseFile()
{
	std::ifstream	csv(this->fileName);



	std::cout << csv << std::endl;
	return (0);
}
