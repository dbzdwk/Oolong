#pragma once

#include "comdef.h"
#include "threadsafelist.h"

namespace Oolong {
	class observer;
	class observable
	{
	private:
		threadsafe_list<observer> observers_;
	public:
		void register_(observer observer);
		void unregister(observer observer);
	};
}