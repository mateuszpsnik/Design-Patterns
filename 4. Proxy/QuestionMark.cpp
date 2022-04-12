#include <iostream>

#include "QuestionMark.h"

//QuestionMark::QuestionMark(const IKey& key)
//{
//	wrappee = std::make_unique<IKey>(key);
//}

char QuestionMark::get_key() const
{
	return wrappee.get_key();
}

void QuestionMark::notify() const
{
	wrappee.notify();
	std::cout << "?\n";
}

bool QuestionMark::operator==(const IKey& rhs) const
{
	return wrappee.get_key() == rhs.get_key();
}