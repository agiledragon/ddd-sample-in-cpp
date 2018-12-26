#include "domain/model/rich-man/RichMan.h"

RichMan::RichMan(const std::string& manId, const std::string& name, Gender gender,
			const std::string& phoneNumber, U32 initAmount)
: AggregateRoot(manId), ManInfo(manId, name, gender, phoneNumber, initAmount)
{

}
