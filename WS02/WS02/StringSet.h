#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Jan 29.2021
#ifndef _STRINGSET_H
#define _STRINGSET_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
namespace sdds {
	class StringSet
	{
		string* m_str;
		size_t m_counter;
	public:
		StringSet();
		~StringSet();
		StringSet(const string& filename);
		size_t size();
		std::string operator[](size_t value);
				
		StringSet& operator = (const StringSet& obj); //copy operator
		StringSet(const StringSet& obj);
		StringSet& operator = (StringSet&& obj); //move operator
		StringSet(StringSet&& obj); 

	};
}
#endif
