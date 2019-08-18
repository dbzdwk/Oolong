#include "threadwrap.h"
#include "oothread.h"
#include "eventcore.h"

namespace Oolong {
	Oothreadwrap::Oothreadwrap():thread_(std::bind(&Oothreadwrap::threadfunc, this))
	{

	}

	Oothreadwrap::~Oothreadwrap()
	{
		if (eventcore_ != nullptr)
		{

		}
	}

	void Oothreadwrap::threadfunc()
	{
		eventcore ec;
		if (initcallback_)
		{
			initcallback_(&ec);
		}

		{
			std::lock_guard<std::mutex> lock(mutex_);
			eventcore_ = &ec;
			cond_.notify_one();
		}

		eventcore_->workloop();

		std::lock_guard<std::mutex> lock(mutex_);
		if (shutdowncallback_ != nullptr)
		{
			shutdowncallback_(&ec);
		}
		eventcore_ = nullptr;
	}

	eventcore* Oothreadwrap::startwork()
	{
		thread_.start();
		std::unique_lock<std::mutex> lk(mutex_);
		cond_.wait(lk, [this] {return eventcore_ != nullptr; });
		return eventcore_;
	}

}