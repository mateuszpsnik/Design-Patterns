#pragma once

#include "AbstractGeneratorFactory.h"
#include "RandomShuffleSorted.h"

class ShuffleSortedFactory : public AbstractGeneratorFactory
{
public:
	ShuffleSortedFactory(int n, int m) : m_n(n), m_m(m) { }

	std::unique_ptr<IGenerator> CreateGenerator() const override
	{
		return std::make_unique<RandomShuffleSorted>(m_n, m_m);
	}

private:
	int m_n, m_m;
};