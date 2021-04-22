// Name: Yuelin Wen
// Seneca Student ID: 114379209
// Seneca email: ywen26@myseneca.ca
// Date of completion: March.21.2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter;
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string token;
		size_t pos = str.find(m_delimiter, next_pos);
		if (pos == next_pos)
		{
			token = {};
			more = false;
			throw "delimiter not found at" + next_pos;
		}
		else
		{
			token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
			m_widthField = std::max(m_widthField, token.size());
			if (pos != std::string::npos)
			{
				more = true;
			}
			else
			{
				more = false;
			}		
		}
		return token;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

}
