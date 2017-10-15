#include "Manager.h"
#include <iostream>

template<class T>
bool ResourceManager<T>::unload(std::string dPath)
{
	typename std::list<Resource<T>*>::iterator it = data.begin();
	for (it = data.begin(); it != data.end(); it++)
	{
		if ((*it)->path == dPath)
		{
			delete (*it);
			data.erase(it);
		}
	}

	return true;
}

