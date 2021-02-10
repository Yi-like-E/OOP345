#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Feb.07.2021
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SET_H
#define _SET_H
#include <iostream>
namespace sdds {
	template <unsigned N, typename T>
	class Set {
		T m_collect[N];
		size_t m_num;
	public:
		Set() :m_collect{}, m_num{}{};
		size_t size() const {
			return m_num;
		};
		const T& get(size_t idx) const {
			return m_collect[idx];
		};
		void operator+=(const T& item) {
			if (m_num < N)
			{
				m_collect[m_num] = item;
				m_num++;
			}
		};
	};
}
#endif