#pragma once

#include <memory>
#include <vector>
#include <string_view>

#include "IKey.h"

class Keyboard
{
public:
	static std::shared_ptr<Keyboard> get_instance(const char key);

	void add(const std::shared_ptr<IKey>& key);
	void add(std::shared_ptr<IKey>&& key);
	void remove(const std::shared_ptr<IKey>& key);

	void notify_keys();

	// Forbid cloning and assigning
	Keyboard(Keyboard&) = delete;
	void operator=(const Keyboard&) = delete;

private:
	static std::shared_ptr<Keyboard> instance;
	Keyboard(char key) : k_pressed(key) {}
	
	char k_pressed = 0;
	std::vector<std::shared_ptr<IKey>> keys;
};