#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"
#include <iomanip>

namespace sdds {
	Reservation::Reservation()
	{
		m_id = {};
		m_name = {};
		m_email = {};
		m_numOfPeople = 0u;
		m_date = 1;
		m_hour = 1;
	}

	Reservation::Reservation(const std::string& res)
	{
		std::string temp;
		temp = res;
		int pos;
		//create temp value for each member variables;	
		std::string id = {};
		std::string name = {};
		std::string email = {};
		int numOfPeople = 0;
		int date = 1;
		int hour = 1;


		//find id
		pos = temp.find(":");
		id = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		id.erase(0, id.find_first_not_of(" "));
		id.erase(id.find_last_not_of(" ") + 1);

		//find name
		pos = temp.find(",");
		name = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		name.erase(0, name.find_first_not_of(" "));
		name.erase(name.find_last_not_of(" ") + 1);

		//erase space in res string
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());

		//find email
		pos = temp.find(",");
		email = temp.substr(0, pos);
		temp.erase(0, pos + 1);

		//find noOfPeople
		pos = temp.find(",");
		if (pos == 1)
		{
			numOfPeople = std::stoi(temp.substr(0, pos));
		}
		else
		{
			numOfPeople = std::stoi(temp.substr(0, pos - 1));
		}
		temp.erase(0, pos + 1);

		//find day
		pos = temp.find(",");
		if (pos == 1)
		{
			date = std::stoi(temp.substr(0, pos));
		}
		else
		{
			date = std::stoi(temp.substr(0, pos - 1));
		}
		temp.erase(0, pos + 1);

		//find time
		hour = std::stoi(temp);

		//assgin values
		m_id = id;
		m_name = name;
		m_email = email;
		m_numOfPeople = numOfPeople;
		m_date = date;
		m_hour = hour;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation ";
		os.width(10);
		os.setf(std::ios::right);
		os << res.m_id << ": ";
		/*os.width(20);
		os.setf(std::ios::right);*/
		os << std::right << std::setw(20);
		os << res.m_name;
		os << "  ";
		os.unsetf(std::ios::right);

		os.setf(std::ios::left);
		os.width(20);

		std::string temp = "<";
		temp.append(res.m_email);  // NEW KNOWLEDGE HOW TO USE "APPEND" :), THIS STEP IS SO HARD TO CONNECT EMAIL TOGETHER
		temp.append(">");
		os << temp;

		os << "    ";
		if (res.m_hour >= 6 && res.m_hour <= 9)
		{
			os << "Breakfast";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			os << "Lunch";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			os << "Dinner";
		}
		else
		{
			os << "Drinks";
		}

		os << " on day " << res.m_date << " @ ";
		os << res.m_hour;
		os << ":00 for " << res.m_numOfPeople;
		if (res.m_numOfPeople == 1)
		{
			os << " person." << std::endl;
		}
		else
		{
			os << " people." << std::endl;
		}
		// TODO: insert return statement here
		return os;
	}
}

