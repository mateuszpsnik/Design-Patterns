#include <iostream>
#include <memory>

#include "AbstractGeneratorFactory.h"

#include "ShuffleSortedFactory.h"
#include "ShuffleFactory.h"
#include "IotaFactory.h"

std::unique_ptr<IGenerator> create_generator(int n, int m, bool sorted)
{
	std::unique_ptr<AbstractGeneratorFactory> factory;

	if (n == m)
	{
		factory = std::make_unique<IotaFactory>(n, sorted);
	}
	else if (sorted)
	{
		factory = std::make_unique<ShuffleSortedFactory>(n, m);
	}
	else
	{
		factory = std::make_unique<ShuffleFactory>(n, m);
	}
	
	return factory->CreateGenerator();
}

void print_sequence(int n, int m, bool sorted)
{
	auto generator = create_generator(n, m, sorted);
	auto sequence = generator->generate_sequence();

	for (const auto& el : sequence)
	{
		std::cout << el << " ";
	}
	std::cout << '\n';
}

int main()
{
	print_sequence(10, 5, true);
	print_sequence(10, 5, false);
	print_sequence(5, 5, true);
	print_sequence(5, 5, false);
}
