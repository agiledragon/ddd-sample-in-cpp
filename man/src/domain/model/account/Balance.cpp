#include "domain/model/account/Balance.h"


Balance::Balance(U32 initAmount) : amount(initAmount)
{

}

bool Balance::operator==(ValueObject* rhs)
{
	return amount == dynamic_cast<Balance*>(rhs)->amount;
}

void Balance::increase(U32 amount)
{
	this->amount += amount;
}

void Balance::decrease(U32 amount)
{
	this->amount -= amount;
}

U32 Balance::get() const
{
	return amount;
}
