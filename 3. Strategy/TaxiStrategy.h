#pragma once

#include "Risk.h"
#include "VehicleStrategy.h"

class TaxiStrategy : public VehicleStrategy
{
public:
	std::string_view ride() const;
};


