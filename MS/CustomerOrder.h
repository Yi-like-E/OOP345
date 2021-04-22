#pragma once
// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: March.25.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{ 0 };
		Item** m_lstItem{};
		static size_t m_widthField;
	public:
		//rule of FIVE
		CustomerOrder() {};  //default constructor
		CustomerOrder(const std::string str);  //1 argument constructor

		CustomerOrder& operator=(const CustomerOrder& obj) = delete;  //copy assignmetn operator
		CustomerOrder(const CustomerOrder& obj) { throw "copy operator not allow"; };//copy constructor

		CustomerOrder(CustomerOrder&& obj)noexcept;//move constructor
		CustomerOrder& operator=(CustomerOrder&& obj)noexcept; //move assignemnt operator
		~CustomerOrder(); //destructor

		bool isFilled() const;  //returns true if all the items in the order have been filled;
		bool isItemFilled(const std::string& itemName) const;  //returns true if all items specified by itemName have been filled
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !ORDER_H



