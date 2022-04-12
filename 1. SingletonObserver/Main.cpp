#include <iostream>

#include "IKey.h"
#include "Key.h"
#include "Keyboard.h"

int main()
{
	auto keyboard = Keyboard::get_instance('j');

	auto k1 = std::make_shared<Key>('a');
	auto k2 = std::make_shared<Key>('b');
	auto k3 = std::make_shared<Key>('j');
	auto k4 = std::make_shared<Key>('k');
	auto k5 = std::make_shared<Key>('i');

	keyboard->add(std::move(k1));
	keyboard->add(std::move(k2));
	keyboard->add(std::move(k3));
	keyboard->add(std::move(k4));
	keyboard->add(std::move(k5));

	keyboard->notify_keys();
}