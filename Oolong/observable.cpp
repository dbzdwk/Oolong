#include "observable.h"
#include "observer.h"
namespace Oolong {

	void observable::register_(observer observer)
	{
		observers_.push_back(observer);
	}

	void observable::unregister(observer observer)
	{

	}
}