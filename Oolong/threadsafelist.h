#pragma once
#include "comdef.h"

namespace Oolong {

	//template<typename RET, typename... ARGS>
	//class AnyFunction<RET(ARGS...)>()
	//{
	//public:
	//	AnyFunction(Function&& func) : f(func) {}
	//	typedef std::function<RET(ARGS...)> Function;
	//	RET operator() (ARGS&&... args)
	//	{
	//		return f(args);
	//	}
	//private:
	//	Function f;
	//}

	template<typename _element>
	class threadsafe_list
	{
	private:
		std::list<std::shared_ptr<_element>> m_List;
		std::mutex m_lock;
	public:
		void push_back(_element element)
		{
			std::lock_guard<std::mutex> lockguard(m_lock);
			std::shared_ptr<_element> new_data(std::make_shared<_element>(std::move(element)));
			m_List.push_back(new_data);
		}

		std::shared_ptr<_element> pop_front()
		{
			std::lock_guard<std::mutex> lockguard(m_lock);
			std::shared_ptr<_element> element;
			if (!m_List.empty())
			{
				element = m_List.front();
				m_List.pop_front();
			}
			return element;
		}

		bool erase(_element element)
		{

		}

		bool empty()
		{
			std::lock_guard<std::mutex> lockguard(m_lock);
			return m_List.empty();
		}

		void clear()
		{
			std::lock_guard<std::mutex> lockguard(m_lock);
			m_List.clear();
		}
	};


}
