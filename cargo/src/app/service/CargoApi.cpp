#include "app/service/CargoApi.h"
#include "app/service/CargoMsg.h"
#include "domain/service/CargoService.h"
#include "domain/model/Cargo.h"

CargoApi::CargoApi(CargoService *service) : service(service)
{

}

void CargoApi::createCargo(CargoMsg* msg)
{
	service->create(msg->getCargoId(), msg->getAfterDays());
}

void CargoApi::delay(int cargoId, int days)
{
	service->delay(cargoId, days);
}
