#pragma once

#include <memory>
#include <exception>
#include <string>
#include <cstdlib>

#include "IKey.h"

class ProxyKey : public IKey
{
public:
	ProxyKey(char key);

	char get_key() const override;
	void notify() const override;

	bool operator==(const IKey& rhs) const override;
private:
	std::unique_ptr<IKey> key = nullptr;
};

class ProxyKeyException : public std::exception
{
public:
	ProxyKeyException(const char* key);

	const char* what() const noexcept override
	{
		return message.c_str();
	}

private:
	const char* k = "";
	std::string message;
};