#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace seneca 
{
	template<typename T>
	class Collection
	{
	private:
		std::string m_name{};
		T* m_items{};
		size_t m_size{ 0 };
		void (*m_observer)(const Collection<T>&, const T&) { nullptr };


	public:
		Collection(const std::string& name) {
			m_name = name;
			m_items = nullptr;
			m_size = 0;
			m_observer = nullptr;
		}

		Collection(Collection&) = delete;

		Collection& operator=(Collection&) = delete;

		~Collection() 
		{
			delete[] m_items;
			m_items = nullptr;
		}

		const std::string& name() const { return m_name; }

		size_t size() const { return m_size; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) 
		{
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool ok = false;

			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == item.title()) {
					ok = true;
				}
			}

			if (!ok) {
				T* temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					temp[i] = m_items[i];
				}

				delete[] m_items;
				m_items = nullptr;

				m_size++;
				m_items = new T[m_size];

				for (size_t i = 0; i < m_size; i++) {
					m_items[i] = temp[i];
				}
				delete[] temp;
				temp = nullptr;
				m_items[m_size - 1] = item;
				if (m_observer != nullptr) {
					m_observer(*this, item);
				}
				
			}

			return *this;
		}

		T& operator[](size_t idx) const 
		{
			if (m_size <= idx) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			else {
				return m_items[idx];
			}
		}

		T* operator[](const std::string& title) const 
		{
			for (size_t i = 0; i < m_size; i++) 
			{
				if (m_items[i].title() == title) 
				{
					return &m_items[i];
				}
			}
			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& os, Collection& src) 
		{
			for (size_t i = 0; i < src.size(); i++) {
				os << src.m_items[i];
			}
			return os;
		}

	};

}   // namespace seneca

#endif
