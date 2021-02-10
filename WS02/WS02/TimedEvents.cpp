#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <iomanip>
namespace sdds{
	sdds::TimedEvents::TimedEvents()
{
	m_num = 0;
	for (int i = 0; i < MAX; i++)
	{
		event[i].eventName = "";
	}
}

void sdds::TimedEvents::startClock()
{
	m_startTime = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::stopClock()
{
	m_endTime = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::addEvent(const char* name)
{
	event[m_num].eventName = name;
	event[m_num].unitOfTime = "nanoseconds";
	event[m_num].durTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
	m_num++;
}

ostream& operator<<(std::ostream& os, const sdds::TimedEvents& obj)
{
	os << "--------------------------" << endl;
	os << "Execution Times:\n";
	os << "--------------------------" << endl;
	for (int i = 0; i < obj.m_num; i++)
	{
		os << setw(21) << left << obj.event[i].eventName << " ";
		os << setw(13) << right << obj.event[i].durTime.count() << " ";
		os << obj.event[i].unitOfTime << endl;
	}
	os << "--------------------------" << endl;

	// TODO: insert return statement here
	return os;
}

}
