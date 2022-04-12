#include <iostream>

#include "IKey.h"
#include "Key.h"
#include "Keyboard.h"
#include "ExclamationMark.h"
#include "QuestionMark.h"
#include "ProxyKey.h"

int main()
{
	auto keyboard = Keyboard::get_instance('p');

	try
	{
		//auto k1 = std::make_shared<ProxyKey>('a');
		/*auto k2 = std::make_shared<Key>('b');
		auto k3 = std::make_shared<Key>('k');
		auto k4 = std::make_shared<ProxyKey>('i');*/

		ProxyKey k5('p');
		ProxyKey k6('p');
		auto k5_wrapped = std::make_shared<ExclamationMark>(k5);
		auto k6_wrapped = std::make_shared<QuestionMark>(k6);

		/*keyboard->add(std::move(k1));
		keyboard->add(std::move(k2));
		keyboard->add(std::move(k3));
		keyboard->add(std::move(k4));*/
		keyboard->add(std::move(k5_wrapped));
		keyboard->add(std::move(k6_wrapped));

		keyboard->notify_keys();
	}
	catch (const ProxyKeyException& ex)
	{
		std::cout << ex.what() << '\n';
	}
}