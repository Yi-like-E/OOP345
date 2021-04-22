// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: March.21.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>
#include <exception>

namespace sdds {
	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;       //delimiter
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};

}
#endif // !UTILITIES_H
