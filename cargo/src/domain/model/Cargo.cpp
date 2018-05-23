#include "domain/model/cargo.h"

Cargo::Cargo(int id, Delivery delivery) : AggregateRoot(id), delivery(delivery)
{

}

Cargo::~Cargo()
{

}

void Cargo::delay(int days)
{
	int afterDays = delivery.getAfterDays();
	delivery = Delivery(afterDays + days);
}

int Cargo::getAfterDays() const
{
	return delivery.getAfterDays();
}
