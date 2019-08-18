#include "threadwrappool.h"
#include "threadwrap.h"

namespace Oolong {

	void threadwrappool::reg(std::unique_ptr<Oothreadwrap> wrap)
	{
		if (threads_.size() < maxthreadnum_)
		{
			threads_.push_back(wrap);
		}
	}

	void threadwrappool::starttotalwork()
	{
		for (int i = 0; i < threads_.size(); i++)
		{
			threads_[i]->startwork();
		}
	}

}