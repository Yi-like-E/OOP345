//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Jan 19.2021
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <cstring>
#include<iostream>

using namespace std;
unsigned int g_sysClock;
namespace sdds {
	Event::Event() {
		m_desc = nullptr;
		m_time = 0;
	}
	Event::~Event() {
		m_desc = nullptr;
		delete[] m_desc;

	}
	void Event::display()
	{
		int hour, minute, sec;
		static int counter = 0;
		hour = m_time / (60 * 60);      //calculate time, please forgive me if you think my methond is not smart :)
		minute = (m_time % (60 * 60)) / 60;
		sec = (m_time % (60 * 60)) % 60;
		counter++;
		if (m_desc != nullptr)
		{
			cout.width(2);
			cout.fill(' ');
			cout << counter;
			cout << ". ";
			cout.width(2);
			cout.fill('0');
			cout << hour;
			cout << ":";
			cout.width(2);
			cout.fill('0');
			cout << minute;
			cout << ":";
			cout.width(2);
			cout.fill('0');
			cout << sec;
			cout << " => " << m_desc << endl;
		}
		else {
			cout.width(2);
			cout.fill(' ');
			cout << counter;
			cout << ". | No Event |" << endl;
		}
	}
	Event::Event(const Event& RO)
	{
		*this = RO;          //copy constructor by using = operator
	}
	void Event::set(const char* address)
	{
		if (address != nullptr && address[0] != '\0')
		{
			if (m_desc != nullptr)
			{
				m_desc = nullptr;
				delete[] m_desc;
			}
			m_desc = new char[strlen(address) + 1];
			strcpy(m_desc, address);
			m_time = g_sysClock;
		}
		else
		{
			m_desc = nullptr;
			delete[] m_desc;
			m_time = 0;
		}
	}
	Event& Event::operator=(const Event& RO)
	{
		if (&RO != this)
		{
			if (RO.m_desc != nullptr)
			{
				if (m_desc != nullptr) {
					m_desc = nullptr;
					delete[]m_desc;
				}
				m_desc = new char[strlen(RO.m_desc) + 1];
				strcpy(m_desc, RO.m_desc);
				m_time = RO.m_time;
			}
			else
			{
				m_desc = nullptr;
				delete[] m_desc;
				m_time = 0;
			}
		}

		// TODO: insert return statement here
		return *this;
	}
	void Event::set()
	{
		m_desc = nullptr;
		m_time = 0;
	}
}

