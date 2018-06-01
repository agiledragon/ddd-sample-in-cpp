#ifndef HAC2CA318_FDDF_48EB_BEF5_E022B99552F3
#define HAC2CA318_FDDF_48EB_BEF5_E022B99552F3

struct Cargo;

struct CargoProvider
{
	virtual ~CargoProvider() = default;

	virtual void confirm(Cargo* cargo) = 0;
};

void setCargoProvider(CargoProvider* provider);
CargoProvider* getCargoProvider();

#endif
