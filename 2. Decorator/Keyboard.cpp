#include <algorithm>
#include <stdexcept>

#include "Keyboard.h"

std::shared_ptr<Keyboard> Keyboard::instance = nullptr;

std::shared_ptr<Keyboard> Keyboard::get_instance(const char key)
{
	if (instance == nullptr)
	{
		auto ptr = new Keyboard(key);
		instance = std::shared_ptr<Keyboard>(ptr);
		//instance = std::make_shared<Keyboard>(key);
	}

	return instance;
}

void Keyboard::add(const std::shared_ptr<IKey>& key)
{
	keys.push_back(key);
}

void Keyboard::add(std::shared_ptr<IKey>&& key)
{
	keys.push_back(std::move(key));
}

void Keyboard::remove(const std::shared_ptr<IKey>& key)
{
	auto index = -1;

	for (std::size_t i = 0; i < keys.size(); ++i) 
	{
		if (*keys[i].get() == *key.get())
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		throw std::runtime_error("no element was found");
	}

	keys.erase(keys.begin() + index);
}

void Keyboard::notify_keys()
{
	std::vector<std::shared_ptr<IKey>> notified_keys;

	for (const auto& key : keys)
	{
		if (k_pressed == key->get_key())
		{
			key->notify();
			notified_keys.push_back(key);
		}
	}

	for (const auto& key : notified_keys)
	{
		remove(key);
	}
}