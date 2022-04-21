#pragma once

#include "AbstractGeneratorFactory.h"
#include "RandomShuffle.h"

class ShuffleFactory : public AbstractGeneratorFactory
{
public:
	ShuffleFactory(int n, int m) : m_n(n), m_m(m) { }

	std::unique_ptr<IGenerator> CreateGenerator() const override
	{
		return std::make_unique<RandomShuffle>(m_n, m_m);
	}

private:
	int m_n, m_m;
};