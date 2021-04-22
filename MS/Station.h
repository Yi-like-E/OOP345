// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: March.21.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {
	class Station
	{
		int m_id = 0;   //station id
		std::string m_name = {};   //item name
		std::string m_desc = {};  //description of the station
		size_t m_serNum = 0;   //the next serial number
		size_t m_stock = 0;   //number of items in stock
		static size_t m_widthField;
		static int id_generator;
	public:
		Station() {};
		Station(std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}
#endif // !STATION_h



