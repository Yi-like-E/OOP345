#pragma once
// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: April.10.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
namespace sdds {
	inline std::deque<CustomerOrder>pending; //to be placed
	inline std::deque<CustomerOrder>completed; //filled removed
	inline std::deque<CustomerOrder>incomplete; //not filled removed
	class Workstation : public Station
	{
		std::deque<CustomerOrder>m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation(std::string& str);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		const Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};

}

#endif // !WORKSTATION_H