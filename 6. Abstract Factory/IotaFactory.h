#pragma once

#include "AbstractGeneratorFactory.h"
#include "Iota.h"

class IotaFactory : public AbstractGeneratorFactory
{
public:
	IotaFactory(int n, bool sorted) : m_n(n), m_sorted(sorted) {}

	std::unique_ptr<IGenerator> CreateGenerator() const override
	{
		return std::make_unique<Iota>(m_n, m_sorted);
	}

private:
	int m_n;
	bool m_sorted;
};