#define _CRT_SECURE_NO_WARNINGS
#include "LineManager.h"
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities u;
		std::ifstream f(file);
		if (!f)
		{
			throw std::string("error, cannot open file");
		}
		else
		{
			std::string str = "";    //read each line
			std::string current = "";   //current workstation words
			std::string next = "";   //next workstation words
			bool more;
			size_t pos = 0;
			Workstation* currentSt = nullptr;     //current station
			Workstation* nextSt = nullptr;       //next station
			Workstation* firstSt = nullptr;     //used to mark the current station in container
			while (std::getline(f, str))
			{
				current = u.extractToken(str, pos, more);   //read token
				currentSt = *std::find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
					return stations->getItemName() == current;
					});//find the same words
				activeLine.push_back(currentSt);  //added to container
				if (more) //read next token
				{
					next = u.extractToken(str, pos, more);
					nextSt = *std::find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
						return stations->getItemName() == next;
						});
					currentSt->setNextStation(nextSt);
				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* tmp) {
				firstSt = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getNextStation() == firstSt;
					});
				});
			m_firstStation = firstSt;  //assign current station to member variable
		}
		f.close();
		m_cntCustomerOrder = pending.size();  //update count
	}
	void LineManager::linkStations()
	{
		const Workstation* station = m_firstStation;
		size_t i = 0;
		do
		{
			activeLine[i++] = const_cast<Workstation*>(station);
			station = station->getNextStation();
		} while (station != nullptr);
	}
	bool LineManager::run(std::ostream& os)
	{
		bool flag = false;
		static size_t cnt = 0;    //track current iteration number
		os << "Line Manager Iteration: " << ++cnt << std::endl;

		if (!pending.empty())
		{
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}


		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->attemptToMoveOrder();
		}

		if (completed.size() + incomplete.size() == m_cntCustomerOrder)
		{
			flag = true;
		}
		return flag;
	}
	void LineManager::display(std::ostream& os) const
	{
		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->display(os);
		}
	}
}