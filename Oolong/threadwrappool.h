#pragma once
#include "comdef.h"

namespace Oolong {

	class Oothreadwrap;
	class threadwrappool
	{
	public:
		void setmaxthreadnum(int num)
		{
			maxthreadnum_ = num;
		}
		void reg(std::unique_ptr<Oothreadwrap> wrap);
		void starttotalwork();
	private:
		int maxthreadnum_;
		std::vector<std::unique_ptr<Oothreadwrap>> threads_;
	};

}