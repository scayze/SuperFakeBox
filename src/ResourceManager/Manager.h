#ifndef ResourceManager_H
#define ResourceManager_H

#include <list>
#include <iostream>
#include "Resource.h"

template<class T>
class ResourceManager
{
protected:

	std::list<Resource<T>*> data;

	virtual T& load(std::string dPath) = 0;
	bool unload(std::string dPath);

public:

	const T& get(std::string dPath)
	{
		typename std::list<Resource<T>*>::iterator it = data.begin();
		for (it = data.begin(); it != data.end(); it++)
		{
			if ((*it)->path == dPath)
			{
				//std::cout << dPath + " load from memory" << std::endl;
				return (*it)->data;
			}
		}
		std::cout << dPath + " load from file" << std::endl;
		return load(dPath);
	}
};



#endif
