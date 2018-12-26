#ifndef H3084BB49_C33B_45EB_93EB_F098C39B5096
#define H3084BB49_C33B_45EB_93EB_F098C39B5096


struct ValueObject
{
	virtual ~ValueObject() = default;

	virtual bool operator==(ValueObject* rhs) = 0;

	bool operator!=(ValueObject* rhs)
	{
		return !operator==(rhs);
	}
};


#endif
