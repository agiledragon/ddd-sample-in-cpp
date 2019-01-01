#ifndef H3EF83865_A784_40BE_ABB0_49AF0B7C4C5D
#define H3EF83865_A784_40BE_ABB0_49AF0B7C4C5D

#include "domain/model/base/Role.h"
#include "pub/base/Keywords.h"


struct Worker : Role
{
	ABSTRACT(void askForLeave());
};



#endif
