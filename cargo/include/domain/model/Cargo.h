#ifndef HF5F02BB5_4582_4EEA_B362_8120E5966FCC
#define HF5F02BB5_4582_4EEA_B362_8120E5966FCC


#include "domain/model/base/AggregateRoot.h"
#include "domain/model/Delivery.h"

struct Cargo : AggregateRoot
{
	Cargo(int id, Delivery delivery);
	~Cargo();

	void delay(int days);
	int getAfterDays() const;

private:
	Delivery delivery;
};


#endif
