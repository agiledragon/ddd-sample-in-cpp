#ifndef H55DDBAD0_6B6F_4444_B5B3_128EDBD5CFA3
#define H55DDBAD0_6B6F_4444_B5B3_128EDBD5CFA3

struct Cargo;

struct CargoRepo
{
	virtual ~CargoRepo() = default;

	virtual void add(Cargo* cargo) = 0;
	virtual Cargo* get(int cargoId) = 0;
	virtual void update(Cargo* cargo) = 0;
	virtual void remove(int cargoId) = 0;
};

void setCargoRepo(CargoRepo* repo);
CargoRepo* getCargoRepo();

#endif
