#pragma once

#include <memory>
#include <iostream>


class Person; /* we only need an address */

class Donation {

	double m_amount;
	const Person& m_donor;

public:
	Donation(const Person& i_donor);

	Donation(const Person& i_donor, int i_val);

	Donation(const Donation& i_donation);

	~Donation();

	const Person& GetDonor() const;

	double GetAmount() const;

	void SetAmount(double i_amount); /* copying an address or a double is pretty much the same, so pass by value */
};

std::ostream& operator<< (std::ostream& stream, const Donation& i_donation);
