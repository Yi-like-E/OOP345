#pragma once
#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <exception>

namespace sdds {
	class Car : public Vehicle
	{
		std::string m_maker = {};
		std::string m_condition = {};
		double m_speed = 0;
	public:
		Car() {};
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !CAR_H



