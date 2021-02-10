#pragma once
//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Jan 29.2021
#ifndef _TIMEDEVENT_H
#define _TIMEDEVENT_H
#include <chrono>
#include <string>
#include <iostream>
using namespace std;
namespace sdds {
	const int MAX = 10;
	class TimedEvents
	{
		int m_num; //num of records
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct {
			string eventName;
			string unitOfTime;
			std::chrono::steady_clock::duration durTime;
		}event[MAX];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& obj);

	};

}


#endif