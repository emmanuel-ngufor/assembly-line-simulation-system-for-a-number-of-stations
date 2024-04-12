#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <vector>
#include <list>

#include "Person.h"

namespace seneca 
{
	class College 
	{
	private:
		std::vector<Person*> m_persons; 

	public:
		College() {};
		College(const College&) = delete;
		College& operator=(const College&) = delete;
		~College();

		College& operator +=(Person* thePerson);
		//First Test
		void display(std::ostream& out) const;

		//Second test
		template <typename T>
		void select(const T& test, std::list<const Person*>& persons)
		{
			for (auto it = m_persons.begin(); it != m_persons.end(); it++)
			{
				if (test(*it))
				{
					persons.push_back(*it);
				}
			}
		}
	};

}   // namespace seneca

#endif // !SENECA_COLLEGE_H
