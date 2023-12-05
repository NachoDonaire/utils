#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>


class BitcoinExchange
{
	private:
		//std::ifstream csvFile;
		std::string		fileName;
 	public:
    		BitcoinExchange();
    		BitcoinExchange(std::string file);
    		BitcoinExchange(const BitcoinExchange &f);
    		~BitcoinExchange();
    		BitcoinExchange& operator=(const BitcoinExchange &f);
			int	errorManagement(int key);
			int	parseFile();
			std::string getFileName();
};

#endif
