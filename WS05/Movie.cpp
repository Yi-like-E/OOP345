#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
namespace sdds {
	sdds::Movie::Movie()
	{
		m_title = {};
		m_year = {};
		m_desc = {};
	}

	const std::string& sdds::Movie::title() const
	{
		// TODO: insert return statement here
		return m_title;
	}

	sdds::Movie::Movie(const std::string& strMovie)
	{
		std::string temp;
		temp = strMovie;
		int pos = 0;
		//create temp value for each member variables;	


		std::string title = m_title;
		size_t year = m_year;
		std::string desc = m_desc;


		//find title
		pos = temp.find(",");
		title = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		title.erase(0, title.find_first_not_of(" "));
		title.erase(title.find_last_not_of(" ") + 1);

		//find year
		pos = temp.find(",");
		year = std::stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1);

		//find desctiption
		desc = temp;

		desc.erase(0, desc.find_first_not_of(" "));
		desc.erase(desc.find_last_not_of(" ") + 1);
		//assgin values

		m_title = title;
		m_year = year;
		m_desc = desc;
	}


	std::ostream& operator<<(std::ostream& os, const Movie& mv)
	{
		os << std::setw(40) << mv.m_title << " | " << std::setw(4) << mv.m_year << " | " << mv.m_desc << std::endl;
		// TODO: insert return statement here
		return os;
	}

}

