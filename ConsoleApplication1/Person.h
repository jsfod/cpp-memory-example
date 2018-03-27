#pragma once

#include <memory>
#include <string>
#include "Address.h"

class Person {

	std::string m_name;
	Address m_address;
	//std::unique_ptr<Address> mp_address;

public:
	Person();

	Person(const std::string& i_name);

	Person(const std::string& i_name, const Address& i_address);

	Person(const Person& i_other);

	~Person();

	Person& operator=(const Person& rhs);

	void SetName(const std::string& i_name);

	const std::string& GetName() const;

	void SetAddress(const Address& i_address);
	const Address& GetAddress() const;
};
