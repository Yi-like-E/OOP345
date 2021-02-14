#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb 12.2021
#ifndef _RESTAURANT_H
#define _RESTAURANT_H
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* m_res;
		size_t m_cnt;
	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& res);
		Restaurant& operator=(const Restaurant& res);
		size_t size() const;
		Restaurant& operator=(Restaurant&& R)noexcept; //move assignment
		Restaurant(Restaurant&& R)noexcept; //move constructor
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}


#endif