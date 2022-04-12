#pragma once
#include "IKey.h"
#include <memory>

class ExclamationMark : public IKey
{
public:
	ExclamationMark(IKey& key) : wrappee(key) {}

	char get_key() const;
	void notify() const;

	bool operator==(const IKey& rhs) const;
private:
	IKey& wrappee;
};
