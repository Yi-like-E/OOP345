#pragma once
#ifndef _COLLECT_H
#define _COLLECT_H
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
namespace sdds {
	template <typename T>
	class Collection
	{
		std::string m_name;
		T* m_arr = nullptr;
		size_t m_size = 0;
		void(*obsFunc)(const Collection<T>&, const T&) = nullptr;
	public:
		//Collection() : m_name{}, m_arr{}, m_size(0){};
		~Collection() {
			delete[] m_arr;
			m_arr = nullptr;
		};
		Collection(const std::string& name) {
			m_name = name;
		};
		/*Collection& operator=(const Collection& c) {
			if (&c != this)
			{
				if (m_arr != nullptr)
				{
					m_arr = nullptr;
					delete[] m_arr;
				}
				m_arr = new T[c.m_size];
				for (size_t i = 0; i < c.m_size; i++)
				{
					m_arr[i] = c.m_size[i];
				}
				m_size=c.m_size;
			}
			return *this;
		};*/
		const std::string& name() const {
			return m_name;
		};
		size_t size() const {
			return m_size;
		};
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			this->obsFunc = observer;
		};
		Collection<T>& operator+=(const T& item) {
			bool flag = false;
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_arr[i].title() == item.title()) {
					flag = true;
				}
			}
			if (!flag)
			{
				T* temp = new T[m_size + 1];

				for (size_t i = 0; i < m_size; i++)
				{
					temp[i] = m_arr[i];
				}
				temp[m_size] = item;

				delete[] m_arr;
				m_arr = temp;
				++m_size;

				if (obsFunc != nullptr) {
					obsFunc(*this, m_arr[m_size - 1]);
				}


			}
			return *this;
		};
		T& operator[](size_t idx) const {
			if (idx >= m_size)
			{
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(m_size);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return m_arr[idx];
		};
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_arr[i].title() == title) {
					return &(m_arr[i]);
				}	
			}
			return nullptr;
		};
		friend std::ostream& operator<<(std::ostream& os, const Collection& c) {
			for (size_t i = 0; i < c.size(); ++i) {
				os << c[i];
			}
			return os;
		};

	};

}


#endif