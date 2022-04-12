#pragma once

#include "Risk.h"
#include "VehicleStrategy.h"

class BicycleStrategy : public VehicleStrategy
{
public:
	std::string_view ride() const;
};