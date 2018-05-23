#ifndef H827DE582_98E8_4C7E_8A74_8D9AB722F799
#define H827DE582_98E8_4C7E_8A74_8D9AB722F799


struct Entity
{
	Entity(int id);

	bool operator==(const Entity* rhs);
	bool operator!=(const Entity* rhs);
	int getId() const;

private:
    int id;
};


#endif
