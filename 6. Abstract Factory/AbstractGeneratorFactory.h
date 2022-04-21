#pragma once

#include "IGenerator.h"

#include <memory>

class AbstractGeneratorFactory
{
public:
	virtual ~AbstractGeneratorFactory() {};

	virtual std::unique_ptr<IGenerator> CreateGenerator() const = 0;
};
