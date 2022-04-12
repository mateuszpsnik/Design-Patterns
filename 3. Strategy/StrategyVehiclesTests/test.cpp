#include "pch.h"

#include <string_view>

#include "../Shipping.h"

Shipping shipping;

TEST(StrategyTest, Taxi)
{
	// all 3
	shipping.choose_strategy(25, 10, Risk::Low);
	EXPECT_EQ(shipping.ride(), "You are riding a taxi");
	// first 2
	shipping.choose_strategy(25, 10, Risk::High);
	EXPECT_EQ(shipping.ride(), "You are riding a taxi");
	// last 2
	shipping.choose_strategy(10, 20, Risk::Low);
	EXPECT_NE(shipping.ride(), "You are riding a taxi");
	// cost and risk
	shipping.choose_strategy(25, 40, Risk::Low);
	EXPECT_EQ(shipping.ride(), "You are riding a taxi");
	// just cost
	shipping.choose_strategy(30, 40, Risk::Average);
	EXPECT_NE(shipping.ride(), "You are riding a taxi");
}

TEST(StrategyTest, Bicycle)
{
	// no money
	shipping.choose_strategy(0, 10, Risk::High);
	EXPECT_EQ(shipping.ride(), "You are riding a bicycle");
	// some money
	shipping.choose_strategy(5, 10, Risk::High);
	EXPECT_NE(shipping.ride(), "You are riding a bicycle");	
}

TEST(StrategyTest, PublicTransport)
{
	// some cases from previous 2 tests that should give public transport
	shipping.choose_strategy(10, 20, Risk::Low);
	EXPECT_EQ(shipping.ride(), "You are riding public transportation");

	shipping.choose_strategy(30, 40, Risk::Average);
	EXPECT_EQ(shipping.ride(), "You are riding public transportation");

	shipping.choose_strategy(5, 10, Risk::Low);
	EXPECT_EQ(shipping.ride(), "You are riding public transportation");
}