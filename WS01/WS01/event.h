//name:Yuelin Wen
//email:ywen26@myseneca.ca
//ID:114379209
//date:Jan 19.2021
#pragma once
#ifndef _EVENT_H
#define _EVENT_H

extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char* m_desc;   //create pointer to store description
		unsigned int m_time; //create unsigned int to store the start time
	public:
		Event(); //default constructor of Event
		~Event(); //deconstructor
		Event(const Event& ro); //copy constructor
		void display(); //display info in format
		void set(); //default transfer and save when nullptr
		void set(const char* address); //transfer and save
		Event& operator=(const Event& RO);//copy assignment operator
	};
}
#endif