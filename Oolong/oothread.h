#pragma once
#include "comdef.h"

namespace Oolong {
	class oothread
	{
	public:
		enum threadstate
		{
			start = 0,
			init,
			running,

		};

		typedef std::function<void()> ThreadFunc;

		oothread(ThreadFunc func);
		void func();
		void start();

	private:
		ThreadFunc func_;
	};
}