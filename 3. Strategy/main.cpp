#include <iostream>
#include <tuple>

#include "Shipping.h"

using std::cout;
using std::cin;

std::tuple<int, int, Risk> get_input()
{
	int time, cost, risk_i;

	cout << "Enter max cost: ";
	cin >> cost;
	cout << "Enter max time: ";
	cin >> time;
	cout << "Enter max risk (0 - low, 1 - average, 2 - high): ";
	cin >> risk_i;

	auto risk = Risk(risk_i);

	return std::make_tuple(cost, time, risk);
}

int main()
{
	auto [cost, time, risk] = get_input();

	Shipping shipping;
	shipping.choose_strategy(time, cost, risk);
	shipping.ride();
}
