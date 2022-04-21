#pragma once

#include "IGenerator.h"

class RandomShuffle : public IGenerator
{
public:
	RandomShuffle(int n, int m) : m_n(n), m_m(m) { }

	std::vector<int> generate_sequence() const override;
private:
	int m_n, m_m;
};