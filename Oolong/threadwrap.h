#pragma once
#include "comdef.h"

namespace Oolong {

	class eventcore;
	class oothread;
	class Oothreadwrap
	{
	public:
		typedef std::function<void(eventcore*)> eventinitcallback;
		typedef std::function<void(eventcore*)> eventshutdowncallback;

		Oothreadwrap();
		~Oothreadwrap();
		eventcore* startwork();

	private:
		void threadfunc();
	private:
		oothread thread_;
		eventcore* eventcore_;
		std::mutex mutex_;
		std::condition_variable cond_;

		eventinitcallback initcallback_;
		eventshutdowncallback shutdowncallback_;
	};
}