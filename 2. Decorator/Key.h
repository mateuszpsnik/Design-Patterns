#pragma once

#include "IKey.h"

class Key : public IKey
{
public:
	Key(char key) : k(key) {}

	char get_key() const;
	void notify() const;

	bool operator==(const IKey& rhs) const;
private:
	char k = 0;
};
