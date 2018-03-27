#pragma once

#include <string>

struct Address
{
	std::string m_address_line1; /* street number box */
	std::string m_address_line2; /* postal code city */
	std::string m_address_line3; /* country */

	Address();
	~Address();

	Address(const Address& i_other);
};

