#pragma once
#ifndef _SPELL_H
#define _SPELL_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
namespace sdds {

	class SpellChecker
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t m_cnt[6]{};
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}


#endif