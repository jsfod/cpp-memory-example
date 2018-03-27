#include "stdafx.h"
#include "Donation.h"
#include "Person.h";


Donation::Donation(const Person& i_donor)
	: m_amount(0)
	, m_donor(i_donor)
{

}

Donation::Donation(const Person& i_donor, int i_val)
	: m_amount(i_val)
	, m_donor(i_donor)
{

}

Donation::Donation(const Donation& i_donation)
	: m_amount(i_donation.m_amount)
	, m_donor(i_donation.m_donor)
{

}

Donation::~Donation() {

}

const Person& Donation::GetDonor() const {
	return m_donor;
}

double Donation::GetAmount() const {
	return m_amount;
}

void Donation::SetAmount(double i_amount) {
	m_amount = i_amount;
}


std::ostream& operator<< (std::ostream& stream, const Donation& i_donation) {
	return stream << i_donation.GetDonor().GetName() << " " << i_donation.GetAmount();
}