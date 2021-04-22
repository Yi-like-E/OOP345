#pragma once
// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: April.10.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <fstream>
#include <functional>
#include <algorithm>
#include "Workstation.h"
namespace sdds {
	class LineManager
	{
		std::vector<Workstation*> activeLine; //collection of current workstations
		size_t m_cntCustomerOrder; //num of orders
		Workstation* m_firstStation = nullptr; //first active station in current line
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // !MANAGER_H


