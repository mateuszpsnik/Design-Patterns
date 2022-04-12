#pragma once

class IKey
{
public:
	virtual ~IKey() {};

	virtual char get_key() const = 0;
	virtual void notify() const = 0;

	virtual bool operator==(const IKey& rhs) const = 0;
};