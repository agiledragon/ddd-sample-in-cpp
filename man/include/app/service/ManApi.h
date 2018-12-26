#ifndef H2CD498B4_A92F_47B5_860A_13EEED011A49
#define H2CD498B4_A92F_47B5_860A_13EEED011A49

#include "pub/base/Types.h"
#include "domain/service/RichManService.h"
#include "domain/service/PoorManService.h"

#include <string>

struct ManApi
{
	ManApi();

	std::string createRichMan(const std::string& name, const std::string& phoneNumber);
	std::string createPoorMan(const std::string& name, const std::string& phoneNumber);
	U32 getRichManAmount(const std::string& manId);
	U32 getPoorManAmount(const std::string& manId);
	void happyNewYear2019(const std::string& richManId, const std::string& poorManId, U32 amount);
	void destroyRichMan(const std::string& manId);
	void destroyPoorMan(const std::string& manId);

private:
	Gender decideGender();

private:
	RichManService richManService;
	PoorManService poorManService;
};


#endif
