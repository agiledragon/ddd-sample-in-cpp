#ifndef HE89A10F9_7C61_47CD_9438_5CA95CC4C8B6
#define HE89A10F9_7C61_47CD_9438_5CA95CC4C8B6

struct CargoRepo;
struct CargoProvider;

struct CargoService
{
	CargoService(CargoRepo* repo, CargoProvider* provider);

	void create(int cargoId, int afterDays);
	void delay(int cargoId, int days);

private:
	CargoRepo* repo;
	CargoProvider* provider;
};



#endif
