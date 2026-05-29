#pragma once

#include "../../Dependencies.h"
#include "../Object/Object.h"

template<class object_t>
class Factory
{
public:

	void addObjectList(std::vector<std::unique_ptr<object_t>>& list)
	{
		m_list_ptr = &list;
	}

	void addCopyObject(const object_t &obj)
	{
		m_object = obj;
	}

	object_t &create()
	{
		m_list_ptr->emplace_back(new object_t());
		*m_list_ptr->back() = m_object;
		return *m_list_ptr->back();
	}

private:
	
	object_t m_object;
	std::vector<std::unique_ptr<object_t>>* m_list_ptr;
};
