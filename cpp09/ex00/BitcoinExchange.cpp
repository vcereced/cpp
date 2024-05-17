/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:35:48 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/19 19:59:32 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

std::string BitcoinExchange::_date = "";
float BitcoinExchange::_rate = 0;

void BitcoinExchange::setDate(std::string &buff)
{
	BitcoinExchange::_date = buff;
}

void BitcoinExchange::setRate(float value)
{
	BitcoinExchange::_rate = value;
}

std::string &BitcoinExchange::getDate(void)
{
	return BitcoinExchange::_date;
}

float &BitcoinExchange::getRate(void)
{
	return BitcoinExchange::_rate;
}

static void checksFormatDate(std::string &_date, std::string &msg_err)
{
	for(size_t i = 0; i < 10; i++)	//check if is '4digits''-''2digits''-''2digits'
	{
		if (_date[i] == '-' && (i == 4 || i == 7))
			continue;
		if(!std::isdigit(_date[i]))
			throw std::runtime_error("Error: bad input => " + msg_err);
	}
	if (_date[10] != '\0')// checks the length
		throw std::runtime_error("Error: bad input => " + msg_err);
}

static int checkValuesDate(std::string &_date, std::string &msg_err)
{
	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = std::atoi(_date.substr(0, 4).c_str()); 	// Copy a substr to a str * to a atoi 
	int month = std::atoi(_date.substr(5, 7).c_str()); 	// Copy a substr to a str * to a atoi 
	int day = std::atoi(_date.substr(8, 10).c_str()); 	// Copy a substr to a str * to a atoi
	
	if (year  < 1900 || year > 2024)
		throw std::runtime_error("Error: bad input year=> " + msg_err);
	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad input month=> " + msg_err);
	if (day < 1 || day > days_in_month[month - 1])
		throw std::runtime_error("Error: bad input  day=> " + msg_err);
	return day;
}

std::string &checkDate(std::string &_date)
{
	std::string msg_err(BitcoinExchange::getDate());	// copy date string to send error
	
	checksFormatDate(_date, msg_err);
	checkValuesDate(_date, msg_err);
	return BitcoinExchange::getDate();
}

std::string &parseDate(std::string &line, char c)
{
	BitcoinExchange::getDate().clear();		//erase the string 
	for (std::string::iterator it = line.begin(); it < std::find(line.begin(), line.end(), c); it++)	//copy till ','
		BitcoinExchange::getDate().push_back(*it);
	return BitcoinExchange::getDate(); 		//return static string
}

float checkRate(std::string tmp, bool csv)
{
	float rate;

	rate = std::stof(tmp);
	if (rate < 0 && !csv)
		throw std::runtime_error("Error: not a positive number.");
	if (rate >= 1000 && !csv)
		throw std::runtime_error("Error: too large a number.");
	return rate;			//return the float value, if error it will catched 
}

std::string parseRate(std::string &line, char c)
{
	std::string tmp; //copy string from ',' to end
	for (std::string::iterator it = std::find(line.begin(), line.end(), c); it < line.end(); it++)
		tmp.push_back(*(it + 1));
	return tmp;
}

static void checkFormat(std::string &line, char c)
{
	if (line.find(' ') !=  std::string::npos) // err if any ' '
		throw std::runtime_error("Error: bad input => " + BitcoinExchange::getDate());
	if (std::count(line.begin(), line.end(), c) != 1) //err if ',' != 1
		throw std::runtime_error("Error: bad input => " + BitcoinExchange::getDate());
	if (line.find(c) != 10)	//err if index of ',' != 10
		throw std::runtime_error("Error: bad input => " + BitcoinExchange::getDate());
}

static void checkHeader(std::ifstream &csv, std::string &line, char c)
{
	std::getline(csv, line);
	
	if (c != '|' && line.find(' ') !=  std::string::npos) // err if any ' '
		throw (BitcoinExchange::ErrorHeader());
	if (std::count(line.begin(), line.end(), c) != 1) //err if ',' != 1
		throw (BitcoinExchange::ErrorHeader());
}

static void isFile(std::string str, std::ifstream &file)
{
	file.open(str);
	if (!file.is_open())
		throw (BitcoinExchange::ErrorFile());
}

void parseCsv(std::ifstream &csv, std::map<std::string, float> &map)
{
	std::string line;
	
	checkHeader(csv, line, ',');
	while (std::getline(csv, line))
	{
		checkFormat(line, ',');
		BitcoinExchange::setDate(checkDate(parseDate(line, ',')));
		BitcoinExchange::setRate(checkRate(parseRate(line, ','), true));
		map[BitcoinExchange::getDate()] = BitcoinExchange::getRate();
	}
}

std::map<std::string, float>::iterator getClosestDate(std::map<std::string, float> &map)
{
	std::map<std::string, float>::iterator closest;

	closest = map.lower_bound(BitcoinExchange::getDate());
	if(closest != map.begin() && closest->first != BitcoinExchange::getDate())
		closest--;
	if (closest == map.end())
		closest--;
	return closest;
}

float calculate(std::map<std::string, float> &map)
{
	return (getClosestDate(map)->second * BitcoinExchange::getRate());
}

void parseInput(std::ifstream &file, std::map<std::string, float> &map)
{
	std::string line;
	
	checkHeader(file, line, '|');
	while (std::getline(file, line))
	{
		try
	 	{
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	 		BitcoinExchange::setDate(checkDate(parseDate(line, '|')));
	 		checkFormat(line, '|');
	 		BitcoinExchange::setRate(checkRate(parseRate(line, '|'), false));
			std::cout << BitcoinExchange::getDate() << " => " << BitcoinExchange::getRate() << " = " << calculate(map) << std::endl;
	 	}
	 	catch(const std::exception& e)
	 	{
	 		std::cerr << e.what() << std::endl;
	 	}
	}
}

void BitcoinExchange::convert(char *str)
{
	std::ifstream stream;
	std::map<std::string, float> map;

	isFile("./data.csv", stream);//throw err if wrong
	parseCsv(stream, map);
	stream.close();
	isFile(str, stream);
	parseInput(stream, map);
	stream.close();
}