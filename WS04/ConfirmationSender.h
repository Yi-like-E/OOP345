#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb 12.2021
#ifndef _CONFIRM_H
#define _CONFIRM_H
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender
	{
		const Reservation** m_cres;
		size_t m_count;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cs); //copy constructor
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender& operator=(const ConfirmationSender& cs); //assignment operator
		ConfirmationSender& operator=(ConfirmationSender&& C)noexcept; //move assignment operator
		ConfirmationSender(ConfirmationSender&& C)noexcept; //move constructor
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);

	};
}


#endif