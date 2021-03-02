#pragma once
#ifndef _BOOK_H
#define _BOOK_H
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
namespace sdds {
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& bk);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		};
	};


}

#endif // !_BOOK_H
