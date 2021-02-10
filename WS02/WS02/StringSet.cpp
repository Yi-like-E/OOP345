#define _CRT_SECURE_NO_WARNINGS
#include "StringSet.h"
#include "TimedEvents.h"
using namespace std;
namespace sdds {
	sdds::StringSet::StringSet()
	{
		m_str = nullptr;
		m_counter = 0;
	}

	sdds::StringSet::~StringSet()
	{
		delete[] m_str;
		m_str = nullptr;
	}

	sdds::StringSet::StringSet(const string& filename)
	{
		static int count = 0;
		string str;
		ifstream file;
		file.open(filename); //step 1
		while (!file.eof()) {

			getline(file, str, ' ');
			count++;
		}
		m_counter = count;
		file.close();

		m_str = new string[m_counter]; //step 2
		static int i = 0;
		file.open(filename); //step 3

		while (!file.eof()) {
			getline(file, str, ' ');
			m_str[i] = str;
			i++;
		}
		file.close();
	}

	size_t sdds::StringSet::size()
	{
		return m_counter;
	}

	std::string sdds::StringSet::operator[](size_t value)
	{
		if (value >= 0 && value < m_counter)
		{
			return m_str[value];
		}
		else
		{
			return "";
		}
	}

	StringSet& StringSet::operator=(const StringSet& obj)
	{
		if (this != &obj)
		{
			m_counter = obj.m_counter;
			delete[] m_str;
			m_str = new string[m_counter];

			/*for (int i = 0; i < m_counter; i++)*/
			for (size_t i = 0; i < m_counter; i++)
			{
				m_str[i] = obj.m_str[i];
			}
		}
		// TODO: insert return statement here
		return *this;
	}

	StringSet::StringSet(const StringSet& obj) :StringSet()
	{
		*this = obj;//
	}

	StringSet& StringSet::operator=(StringSet&& obj)
	{
		if (this != &obj)
		{
			delete[] m_str;
			m_str = obj.m_str;
			m_counter = obj.m_counter;
			obj.m_counter = 0;
			obj.m_str = nullptr;
		}
		// TODO: insert return statement here
		return *this;
	}

	StringSet::StringSet(StringSet&& obj) :StringSet()
	{
		*this = move(obj);//
	}

}