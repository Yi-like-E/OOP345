#pragma once
#ifndef _MOVIE_H
#define _MOVIE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
namespace sdds {
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_desc;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& mv);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
			spellChecker(m_title);
			
		}
	};
}


#endif