// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Donation.h"
#include "Person.h"
#include <memory>
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	//////////////////////////////////////////////////////////////////////////////////////////////
	// Slide 9 - 11
	{
		int myvar = 25;					// create variable with value 25 (gets address 1776)
		int* foo  = &myvar;				// store address 1776 in a pointer
		int bar	  = myvar;				// copy value 25 to another parameter bar
		int& baz  = *foo;				// dereferencing = getting the value from the pointer: baz is equal to the value (25) pointed to by foo (at address 1776)
		int  baz2 = *foo;				// dereferencing and copying into
	}
	
	{
		int a(1);						// on the stack
		int b		= 2;				// on the stack
		int *p_c	= new int;			// p_c is assigned 4 bytes in the heap
		*p_c		= 3;				// p_c is pointing at 3
		int *array	= new int[10];		// array is assigned 40 bytes in the heap
		array[0] = a;
		array[1] = b;
		array[2] = *p_c;				// the value that the pointer is pointing to is copied to the first element of the array

		delete p_c;
		delete[] array;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/// add breakpoints : constructor, copy-constructor and destructor
	/// slide 11
	{
		Person person("Frank");			// on the stack
		Person clone(person);			// copy constructor
		Person& clone_ref = clone;		// creating a reference to the clone
		Person clone_again = clone;		// call copy constructor again

		Donation donation(person, 100);	// on the stack
	} // both person and donation's destructors are called


	//////////////////////////////////////////////////////////////////////////////////////////////
	/// slide 12
	{
		Person frank("Frank");							// on the stack
		Person* p_willy = new Person("Willy");   		// on the heap
		std::cout << frank.GetName() << std::endl;
		std::cout << p_willy->GetName() << std::endl << std::endl;

		Donation donation(*p_willy, 100);								// on the stack
		Donation* p_donation = new Donation(donation);					// create pointer on the heap and call the copy-constructor;
		p_donation->SetAmount(200);										// pass by value
		std::unique_ptr<Donation> up_donation(new Donation(donation));	// up_donation is on the stack, the new donation is on the heap, but will be automatically destructed when up_donation is out of scope
		up_donation->SetAmount(300);									// pass by value

		const Donation& donation_const_ref = donation;					// holding a const reference will prevent us from modifying it

		std::cout << donation << std::endl;
		std::cout << *p_donation << std::endl;
		std::cout << *up_donation << std::endl;

		delete p_donation;		// if not here : memory leak
		delete p_willy;			// idem
	}

	system("pause");
	return 0;
}
