#include <iostream>
#include <stdexcept>
#include <memory>
#include <string_view>

#include "Shipping.h"
#include "TaxiStrategy.h"
#include "BicycleStrategy.h"
#include "PublicTransportStrategy.h"

std::string_view Shipping::ride() const
{
	if (strategy == nullptr)
	{
		std::string error_message = "Error: Strategy was not chosen (nullptr)";
		std::cout << error_message << '\n';
		throw std::runtime_error(error_message);
	}

	return strategy->ride();
}

void Shipping::choose_strategy(int cost, int time, Risk risk)
{
	// high priority - taxi
	if (cost >= 20 && (time < 30 || risk == Risk::Low))
	{
		strategy = std::make_unique<TaxiStrategy>();
	}
	else if (cost < 3)  // no money - bicycle
	{
		strategy = std::make_unique<BicycleStrategy>();
	}
	else // sth in between - public transport
	{
		strategy = std::make_unique<PublicTransportStrategy>();
	}
}