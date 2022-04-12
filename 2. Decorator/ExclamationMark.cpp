#include <iostream>

#include "ExclamationMark.h"

//ExclamationMark::ExclamationMark(const IKey& key)
//{
//	wrappee = std::make_unique<IKey>(key);
//}

char ExclamationMark::get_key() const
{
	return wrappee.get_key();
}

void ExclamationMark::notify() const
{
	wrappee.notify();
	std::cout << "!\n";
}

bool ExclamationMark::operator==(const IKey& rhs) const
{
	return wrappee.get_key() == rhs.get_key();
}