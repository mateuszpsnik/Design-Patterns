#include <iostream>

#include "Key.h"

char Key::get_key() const
{
	return k;
}

void Key::notify() const
{
	std::cout << "The key " << k << " was pressed.";
}

bool Key::operator==(const IKey& rhs) const
{
	return this->k == rhs.get_key();
}