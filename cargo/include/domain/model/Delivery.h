#ifndef HD060CE86_1445_482D_9C9A_A4A2969E0FF3
#define HD060CE86_1445_482D_9C9A_A4A2969E0FF3

#include "domain/model/base/ValueObject.h"

struct Delivery : ValueObject
{
	Delivery(int afterDays);

	virtual bool operator==(ValueObject* rhs) override;
	virtual bool operator!=(ValueObject* rhs) override;
	int getAfterDays() const;

private:
	int afterDays;
};


#endif
