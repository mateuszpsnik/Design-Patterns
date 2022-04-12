#pragma once

#include "IKey.h"

class Key : public IKey
{
public:
	Key(char key) : k(key) {}

	char get_key() const override;
	void notify() const override;

	bool operator==(const IKey& rhs) const override;
private:
	char k = 0;
};
