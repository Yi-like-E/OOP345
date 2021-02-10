#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb.07.2021
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _PAIRSUM_H
#define _PAIRSUM_H
#include "Pair.h"
#include <string>
#include <iostream>
namespace sdds {
	template <typename V, typename K>
	class PairSummable :public Pair<V, K> {
		static V m_initial;
		static size_t m_minw;
	public:
		PairSummable() {};

		PairSummable(const K& key, const V& value = m_initial) :Pair<V, K>(key, value) {
			if (m_minw < key.size())
			{
				m_minw = key.size();
			}
		};

		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return this->key() == b.key();
		};

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj) {
			if (isCompatibleWith(obj))
			{
				this->m_value += obj.value();
			}
			return *this;
		};

		void display(std::ostream& os) const {
			os.setf(std::ios::left); //1.alignment to left
			os.width(m_minw); //2.field width
			Pair<V, K>::display(os);//3.call display() of base class
			os.unsetf(std::ios::left); // 4.restore to the right
		};


	};

	template <typename V, typename K>
	V PairSummable<V, K>::m_initial = {};
	template <typename V, typename K>
	size_t PairSummable<V, K>::m_minw = 0;

	template<> //specialazations
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj) {  //Specializations
		std::string tempstr;
		if (this->value() == "")
		{
			tempstr = obj.value();
		}
		else
		{
			tempstr = this->value() + ", " + obj.value();
		}
		*this = PairSummable(this->key(), tempstr);
		return *this;
	};
}
#endif
