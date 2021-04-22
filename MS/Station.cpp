// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: March.21.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"
#include "Utilities.h"
namespace sdds {

	size_t Station::m_widthField = 1;
	int Station::id_generator = 0;

	Station::Station(std::string& str)
	{
		Utilities u;
		bool more = false;
		size_t pos = 0;

		m_id = ++id_generator;
		//name
		m_name = u.extractToken(str, pos, more);

		//serNum
		m_serNum = stoi(u.extractToken(str, pos, more));

		//stock
		m_stock = stoi(u.extractToken(str, pos, more));

		m_widthField = std::max(m_widthField, u.getFieldWidth());
		//desc
		m_desc = u.extractToken(str, pos, more);
	}
	const std::string& Station::getItemName() const
	{
		// TODO: insert return statement here
		return m_name;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serNum++;
	}
	size_t Station::getQuantity() const
	{
		return m_stock;
	}
	void Station::updateQuantity()
	{
		m_stock--;
		if (m_stock < 0)
		{
			m_stock = 0;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (full)
		{
			os << "[" << std::setfill('0') << std::setw(3) << std::right << m_id;
			os << "] Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
			os << " [" << std::setfill('0') << std::setw(6) << std::right << m_serNum;
			os << "]" << " Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_stock;
			os << " Description: " << m_desc << std::endl;

		}
		else
		{
			os << "[" << std::setfill('0') << std::setw(3) << std::right << m_id;
			os << "] Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
			os << " [" << std::setfill('0') << std::setw(6) << std::right << m_serNum << "]\n";
		}
	}
}