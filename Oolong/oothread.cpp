#include "Oothread.h"

namespace Oolong {

	oothread::oothread(ThreadFunc func) : func_(std::move(func))
	{

	}

	void oothread::func()
	{
		//start the thread loop
	}

	void oothread::start()
	{

	}
}