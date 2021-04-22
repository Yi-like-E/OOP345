#define _CRT_SECURE_NO_WARNINGS
#include "Workstation.h"
namespace sdds {
	Workstation::Workstation(std::string& str) :Station(str) {}
	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool moved = false;
		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(Station::getItemName())) //if the order requires no more service at this station
			{
				if (!m_pNextStation) {
					//if there is no next station in the assembly line, then the order is moved into completed queue
					completed.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
				}
				else
				{
					*m_pNextStation += std::move(m_orders.front());  //move it to the next station
					m_orders.pop_front();
				}
				moved = true;   //moved
			}
			else if (Station::getQuantity() == 0)
			{
				if (!m_pNextStation) {
					//if there is no next station in the assembly line, then the order is moved into incomplete queue
					incomplete.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
				}
				else
				{
					*m_pNextStation += std::move(m_orders.front());  //move it to the next station
					m_orders.pop_front();
				}
				moved = true;   //moved
			}
		}
		return moved;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	const Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation == nullptr)
		{
			os << getItemName() << " --> End of Line" <<  std::endl;
		}
		else
		{
			os << getItemName() << " --> " << getNextStation()->getItemName() << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		// TODO: insert return statement here
		return *this;
	}
}