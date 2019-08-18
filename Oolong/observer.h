#pragma once
#include "comdef.h"

namespace Oolong {
	class observable;
	class observer
	{
	private:
		std::weak_ptr<observable> observable_;
	};
}