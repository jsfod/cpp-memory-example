#include "stdafx.h"
#include "Person.h"


Person::Person(const std::string& i_name) : m_name(i_name), m_address() {

}

Person::Person() : m_name(""), m_address() {

}

Person::Person(const std::string& i_name, const Address& i_address)
	: m_name(i_name)
	, m_address(i_address)
{

}

Person::Person(const Person& i_other)
	: m_name(i_other.m_name)
	, m_address(i_other.m_address)
{

}

Person& Person::operator=(const Person& i_other)
{
	if (this == &i_other)
		return *this;
	m_name = i_other.m_name;
	return *this;
}

Person::~Person() {

}

void Person::SetName(const std::string& i_name) {
	this->m_name = i_name;
}

const std::string& Person::GetName() const {
	return this->m_name;
}

void Person::SetAddress(const Address& i_address) {
	m_address = i_address;
}

const Address& Person::GetAddress() const {
	return m_address;
}
