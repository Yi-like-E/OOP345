#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb 12.2021
#ifndef _RESERVATION_H
#define _RESERVATION_H
#include <iostream>
#include <algorithm>
#include <string>
#include <string>
namespace sdds {
	class Reservation
	{
		std::string m_id;
		std::string m_name;
		std::string m_email;
		int m_numOfPeople;
		int m_date; //1-28
		int m_hour; //1-24
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}

#endif