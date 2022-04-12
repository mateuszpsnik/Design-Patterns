#include "ProxyKey.h"
#include "Key.h"

ProxyKeyException::ProxyKeyException(const char* key = "") : std::exception(key)
{
	message = "Could not create or use a Key object";

	if (key != "")
	{
		message += "\nWrong character: ";
		message += key;
	}
}

ProxyKey::ProxyKey(char key)
{
	switch (key)
	{
		// ignore uppercase
	case 'q':
	case 'w':
	case 'e':
	case 'r':
	case 't':
	case 'y':
	case 'u':
	case 'i':
	case 'o':
	case 'p':
		this->key = std::make_unique<Key>(key);
		break;
	default:
		std::string character(1, key);
		throw ProxyKeyException{character.c_str()};
	}
}

char ProxyKey::get_key() const
{ 
	if (key)
	{
		return key->get_key();
	}
	else
	{
		throw ProxyKeyException{};
	}
}

void ProxyKey::notify() const
{
	if (key)
	{
		return key->notify();
	}
	else
	{
		throw ProxyKeyException{};
	}
}

bool ProxyKey::operator==(const IKey& rhs) const
{
	if (key)
	{
		return key->operator==(rhs);
	}
	else
	{
		throw ProxyKeyException{};
	}
}

