#pragma once
#include <istream>
#include "Car.h"
#ifndef RACE_H
#define RACE_H
namespace sdds {
	class Racecar : public Car
	{
		double m_booster = 0.0; //percentage between 0 and 1
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}


#endif
