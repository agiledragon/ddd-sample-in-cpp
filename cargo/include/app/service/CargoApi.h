#ifndef H8121EA19_8587_4673_B205_FC16729E619E
#define H8121EA19_8587_4673_B205_FC16729E619E

struct CargoService;
struct CargoMsg;
struct Cargo;

struct CargoApi
{
	CargoApi(CargoService* service);

	void createCargo(CargoMsg* msg);
	void delay(int cargoId, int days);

private:
	CargoService* service;
};


#endif
