#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

namespace sdds {
	Book::Book()
	{
		m_author = {};
		m_title = {};
		m_country = {};
		m_year = { 0 };
		m_price = { 0 };
		m_desc = {};
	}
	const std::string& Book::title() const
	{
		// TODO: insert return statement here
		return m_title;
	}
	const std::string& Book::country() const
	{
		// TODO: insert return statement here
		return m_country;
	}
	const size_t& Book::year() const
	{
		// TODO: insert return statement here
		return m_year;
	}
	double& Book::price()
	{
		// TODO: insert return statement here
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		std::string temp;
		temp = strBook;
		int pos = 0;
		//create temp value for each member variables;	

		std::string author = m_author;
		std::string title = m_title;
		std::string country = m_country;
		size_t year = m_year;
		double price = m_price;
		std::string desc = m_desc;


		//find author
		pos = temp.find(",");
		author = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		author.erase(0, author.find_first_not_of(" "));
		author.erase(author.find_last_not_of(" ") + 1);

		//find title
		pos = temp.find(",");
		title = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		title.erase(0, title.find_first_not_of(" "));
		title.erase(title.find_last_not_of(" ") + 1);

		//erase space in res string
		//temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());

		//find country
		pos = temp.find(",");
		country = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		country.erase(0, country.find_first_not_of(" "));
		country.erase(country.find_last_not_of(" ") + 1);
		//find price
		pos = temp.find(",");
		price = std::stod(temp.substr(0, pos));
		temp.erase(0, pos + 1);

		//find year
		pos = temp.find(",");
		year = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);

		//find desctiption
		desc = temp;

		desc.erase(0, desc.find_first_not_of(" "));
		desc.erase(desc.find_last_not_of(" ") + 1);
		//assgin values
		m_author = author;
		m_title = title;
		m_country = country;
		m_year = year;
		m_price = price;
		m_desc = desc;

	}
	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		os << std::setw(20) << bk.m_author << " | " << std::setw(22) << bk.title() << " | " << std::setw(5) << bk.country() << " | " << std::setw(4) << bk.year() << " | " << std::fixed << std::setprecision(2) << std::setw(6) << bk.m_price << " | " << bk.m_desc << std::endl;

		
		// TODO: insert return statement here
		return os;
	}
}