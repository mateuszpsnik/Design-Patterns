#include "RandomShuffle.h"

#include <numeric>
#include <random>

std::vector<int> RandomShuffle::generate_sequence() const
{
	std::vector<int> full_vec(m_n);

	// generate a vector with values 1,2,...,n
	std::iota(full_vec.begin(), full_vec.end(), 1);

	// shuffle the values
	std::random_device rd;
	std::mt19937 rg(rd());
	std::shuffle(full_vec.begin(), full_vec.end(), rg);

	// take m values
	std::vector<int> sub_vec(full_vec.begin(), full_vec.begin() + m_m);

	return sub_vec;
}