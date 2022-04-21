#pragma once

#include "IGenerator.h"

class RandomShuffleSorted : public IGenerator
{
public:
	RandomShuffleSorted(int n, int m) : m_n(n), m_m(m) { }

	std::vector<int> generate_sequence() const override;
private:
	int m_n, m_m;
};