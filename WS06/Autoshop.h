#pragma once
#ifndef AUTO_H
#define AUTO_H
#include <vector>
#include <iostream>
#include "Vehicle.h"
#include <list>

namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++)
			{
				if (test(m_vehicles[i]))
				{
					vehicles.push_back(m_vehicles[i]);
				}
			}
		};
	};

}
#endif // !CAR_H

