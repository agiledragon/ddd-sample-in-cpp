#ifndef H827DE582_98E8_4C7E_8A74_8D9AB722F799
#define H827DE582_98E8_4C7E_8A74_8D9AB722F799

#include <string>

struct Entity
{
	Entity(const std::string& id);

	bool operator==(const Entity* rhs);
	bool operator!=(const Entity* rhs);
	std::string getId() const;

private:
    std::string id;
};


#endif
