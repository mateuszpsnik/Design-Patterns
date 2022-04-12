#pragma once

#include <memory>

#include "Risk.h"
#include "VehicleStrategy.h"

class Shipping
{
public:
	std::string_view ride() const;
	void choose_strategy(int cost, int time, Risk risk);
private:
	std::unique_ptr<VehicleStrategy> strategy = nullptr;
};