#include "Iota.h"

#include <numeric>
#include <random>

std::vector<int> Iota::generate_sequence() const
{
	std::vector<int> full_vec(m_n);

	// generate a vector with values 1,2,...,n
	std::iota(full_vec.begin(), full_vec.end(), 1);

	if (!m_sorted)
	{
		// shuffle the values
		std::random_device rd;
		std::mt19937 rg(rd());
		std::shuffle(full_vec.begin(), full_vec.end(), rg);
	}

	return full_vec;
}