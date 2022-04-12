#include <iostream>

#include "PublicTransportStrategy.h"

std::string_view PublicTransportStrategy::ride() const
{
	return "You are riding public transportation";
}