#ifndef H12243EA5_4479_4B81_9F0F_634BAD28461A
#define H12243EA5_4479_4B81_9F0F_634BAD28461A


struct CargoMsg
{
	CargoMsg(int cargoId, int afterDays);

	int getCargoId() const;
	int getAfterDays() const;

private:
	int cargoId;
	int afterDays;
};


#endif
