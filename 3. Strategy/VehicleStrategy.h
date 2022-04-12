#pragma once

#include <string_view>

#include "Risk.h"

class VehicleStrategy
{
public:
	virtual std::string_view ride() const = 0;
};