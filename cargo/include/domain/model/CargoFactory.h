#ifndef H7F5398E0_B9DB_4055_A925_93A9FBCAB838
#define H7F5398E0_B9DB_4055_A925_93A9FBCAB838

struct Cargo;

struct CargoFactory
{
	Cargo* create(int cargoId, int afterDays);
};


#endif
