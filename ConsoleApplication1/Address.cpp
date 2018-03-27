#include "stdafx.h"
#include "Address.h"


Address::Address()
	: m_address_line1("")
	, m_address_line2("")
	, m_address_line3("")
{
}


Address::~Address()
{
}

Address::Address(const Address& i_other)
	: m_address_line1(i_other.m_address_line1)
	, m_address_line2(i_other.m_address_line2)
	, m_address_line3(i_other.m_address_line3)
{
}

