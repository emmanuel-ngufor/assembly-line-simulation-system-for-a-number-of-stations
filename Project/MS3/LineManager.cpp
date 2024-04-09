#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace seneca
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		Utilities utility;

		std::ifstream input(file);
		if (!input.is_open()) 
		{
			throw std::string("Unable to open file.");
		}


		std::string data;
		while (!input.eof())
		{
			getline(input, data);
			size_t pos = 0;
			bool more = true;
			std::string curStation, nextStation;
			curStation = utility.extractToken(data, pos, more);

			if (more) 
			{
				nextStation = utility.extractToken(data, pos, more);
			}

			Workstation* curWorkstation = nullptr;
			Workstation* nextWorkstation = nullptr;
			for_each(stations.begin(), stations.end(), [&curWorkstation, &nextWorkstation, curStation, nextStation](Workstation* ws) 
				{
				if (ws->getItemName() == curStation) 
				{
					curWorkstation = ws;
				}
				else if (ws->getItemName() == nextStation) 
				{
					nextWorkstation = ws;
				}
				});

			if (m_Active_Line.size() == 0) 
			{
				m_First_Station = curWorkstation;
			}

			curWorkstation->setNextStation(nextWorkstation);
			m_Active_Line.push_back(curWorkstation);
		}

		input.close();

	}

	void LineManager::reorderStations() 
	{
		std::vector<Workstation*> newStations;
		Workstation* lastStation = nullptr;
		unsigned int count = 0;
		while (count < m_Active_Line.size())
		{
			for (unsigned int i = 0; i < m_Active_Line.size(); i++) 
			{
				if (m_Active_Line[i]->getNextStation() == lastStation) 
				{
					newStations.push_back(m_Active_Line[i]);
					lastStation = m_Active_Line[i];
					count++;
					break;
				}
			}
		}
		reverse(newStations.begin(), newStations.end());
		m_First_Station = newStations[0];
		m_Active_Line = newStations;
	}

	bool LineManager::run(std::ostream& os) 
	{
		static int count = 0;
		count++;
		os << "Line Manager Iteration: " << count << std::endl;

		if (!g_pending.empty()) 
		{
			(*m_First_Station) += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for (unsigned int i = 0; i < m_Active_Line.size(); i++) 
		{
			m_Active_Line[i]->fill(os);
		}

		for (unsigned int i = 0; i < m_Active_Line.size(); i++) 
		{
			m_Active_Line[i]->attemptToMoveOrder();
		}

		bool isEmpty = true;
		for (unsigned int i = 0; i < m_Active_Line.size(); i++) 
		{
			if (!m_Active_Line[i]->empty()) 
			{
				isEmpty = false;
				break;
			}
		}

		return isEmpty;
	}

	void LineManager::display(std::ostream& os) const 
	{
		for (unsigned int i = 0; i < m_Active_Line.size(); i++) 
		{
			m_Active_Line[i]->display(os);
		}
	}

}   // namespace seneca