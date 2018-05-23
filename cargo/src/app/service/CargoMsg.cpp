#include "app/service/CargoMsg.h"

CargoMsg::CargoMsg(int cargoId, int afterDays) : cargoId(cargoId), afterDays(afterDays)
{

}

int CargoMsg::getCargoId() const
{
	return cargoId;
}

int CargoMsg::getAfterDays() const
{
	return afterDays;
}
