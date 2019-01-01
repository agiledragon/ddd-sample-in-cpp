#ifndef H8FCF32DC_A391_41A7_8806_75BCF4FDB632
#define H8FCF32DC_A391_41A7_8806_75BCF4FDB632

#include "pub/base/Types.h"

#include <string>

struct RichManRepo;

struct RichManService
{
	RichManService();

	std::string createMan(const std::string& name, Gender gender,
			const std::string& phoneNumber);
	void destroyMan(const std::string& manId);

private:
	RichManRepo* repo;
};



#endif
