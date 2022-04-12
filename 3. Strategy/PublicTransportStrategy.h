#pragma once

#include "Risk.h"
#include "VehicleStrategy.h"

class PublicTransportStrategy : public VehicleStrategy
{
public:
	std::string_view ride() const;
};
