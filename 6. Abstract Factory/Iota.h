#pragma once

#include "IGenerator.h"

class Iota : public IGenerator
{
public:
	Iota(int n, bool sorted) : m_n(n), m_sorted(sorted) {}

	std::vector<int> generate_sequence() const override;
private:
	int m_n;
	bool m_sorted;
};
