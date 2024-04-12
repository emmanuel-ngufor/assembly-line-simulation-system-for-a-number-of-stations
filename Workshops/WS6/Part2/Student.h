#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include <iostream>
#include <string>

#include "Person.h"

namespace seneca 
{
	class Student :public Person 
	{
	private:
		std::string m_name{};
		std::string m_age{};
		std::string m_id{};
		std::string* m_courses{};
		size_t m_count;

	public:
		Student(const Student* src) = delete;
		Student* operator=(const Student* src) = delete;
		~Student();

		Student() { m_count = 0; };
		Student(std::istream& istr);
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SENECA_STUDENT_H