#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb.07.2021
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _PAIR_H
#define _PAIR_H
#include <iostream>
namespace sdds {
	template <typename V, typename K>
	class Pair {
	protected:
		V m_value;
		K m_key;
	public:
		Pair() :m_value{}, m_key{} {};

		Pair(const K& key, const V& value) {
			m_value = value;
			m_key = key;
		};

		const V& value() const {
			return m_value;
		};
		const K& key() const {
			return m_key;
		};

		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		};
	};

	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	};
}

#endif
