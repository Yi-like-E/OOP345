#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* v;
		std::stringstream str;
		std::string temp;
		getline(in, temp, '\n');
		str << temp;
		temp = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find_first_not_of(" "));
		temp.erase(temp.find_last_not_of(" ") + 1);
		if (!temp.empty())
		{
			if (temp[0] == 'c' || temp[0] == 'C')
			{
				v = new Car(str);
			}
			else if (temp[0] == 'r' || temp[0] == 'R')
			{
				v = new Racecar(str);
			}
			else
			{
				/*std::string err = "Unrecognized record type: [t]";
				throw err;*/
				std::string tag{};
				getline(str, tag, ',');
				tag.erase(0, tag.find_first_not_of(" "));
				tag.erase(tag.find_last_not_of(" ") + 1);
				throw "Unrecognized record type: [" + tag + "]";
			}
		}
		else
		{
			v = nullptr;
		}
		return v;
	}

}
