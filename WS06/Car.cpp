#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& is)
	{
		std::string tag, maker, condition, speed;

		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, condition, ',');
		getline(is, speed, ',');

		//tag
		tag.erase(0, tag.find_first_not_of(" "));
		tag.erase(tag.find_last_not_of(" ") + 1);

		//mark
		maker.erase(0, maker.find_first_not_of(" "));
		maker.erase(maker.find_last_not_of(" ") + 1);
		m_maker = maker;

		//condition
		condition.erase(0, condition.find_first_not_of(" "));
		condition.erase(condition.find_last_not_of(" ") + 1);

		//speed
		speed.erase(0, speed.find_first_not_of(" "));
		speed.erase(speed.find_last_not_of(" ") + 1);

		//check condition
		if (condition.empty() || condition == " ")
		{
			m_condition = "new";
		}
		else if (condition == "n")
		{
			m_condition = "new";
		}
		else if (condition == "u")
		{
			m_condition = "used";
		}
		else if (condition == "b")
		{
			m_condition = "broken";
		}
		else
		{
			std::string err = "Invalid record!";
			throw err;
		}

		//check speed
		if (isdigit(speed[0]))
		{
			m_speed = std::stod(speed);
		}
		else
		{
			std::string err = "Invalid record!";
			throw err;
		}


	}
	std::string sdds::Car::condition() const
	{
		return m_condition;
	}

	double sdds::Car::topSpeed() const
	{
		return m_speed;
	}

	void sdds::Car::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(10) << m_maker << " | " << std::left << std::setw(6) << m_condition << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}

