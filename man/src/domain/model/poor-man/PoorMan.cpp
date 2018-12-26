#include "domain/model/poor-man/PoorMan.h"

PoorMan::PoorMan(const std::string& manId, const std::string& name, Gender gender,
			const std::string& phoneNumber, U32 initAmount)
: AggregateRoot(manId), ManInfo(manId, name, gender, phoneNumber, initAmount)
{

}
