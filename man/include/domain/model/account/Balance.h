#ifndef H8ED04DAE_DC37_4869_8841_6961FB722E5F
#define H8ED04DAE_DC37_4869_8841_6961FB722E5F

#include "pub/base/Types.h"
#include "pub/base/Keywords.h"
#include "domain/model/base/ValueObject.h"

struct Balance : ValueObject
{
	Balance(U32 initAmount);

	OVERRIDE(bool operator==(ValueObject* rhs));

	void increase(U32 amount);
	void decrease(U32 amount);
	U32 get() const;

private:
	U32 amount;
};


#endif
