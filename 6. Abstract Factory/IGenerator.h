#pragma once

#include <vector>

class IGenerator
{
public:
	virtual ~IGenerator() {};

	virtual std::vector<int> generate_sequence() const = 0;
};