#include "domain/model/Delivery.h"

Delivery::Delivery(int afterDays) : afterDays(afterDays)
{

}

bool Delivery::operator==(ValueObject* rhs)
{
	return afterDays == dynamic_cast<Delivery*>(rhs)->afterDays;
}

bool Delivery::operator!=(ValueObject* rhs)
{
	return !operator==(rhs);
}

int Delivery::getAfterDays() const
{
	return afterDays;
}
