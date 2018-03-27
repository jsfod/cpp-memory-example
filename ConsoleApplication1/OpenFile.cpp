#include "stdafx.h"
#include "OpenFile.h"

void example_with_RAII()
{
	// open file (acquire resource)
	file logfile("logfile.txt");

	logfile.write("hello logfile!");
	// continue writing to logfile.txt ...

	// logfile.txt will automatically be closed because logfile's
	// destructor is always called when example_with_RAII() returns or
	// throws an exception.
}

void example_without_RAII()
{
	// open file
	std::FILE* file_handle;// = std::fopen("logfile.txt", "w+");
	errno_t err;
	err = fopen_s(&file_handle, "logfile.txt", "w+");
	
	if (file_handle == NULL)
	{
		throw open_error();
	}

	try
	{

		if (std::fputs("hello logfile!", file_handle) == EOF)
		{
			throw write_error();
		}

		// continue writing to logfile.txt ... do not return
		// prematurely, as cleanup happens at the end of this function
	}
	catch (...)
	{
		// manually close logfile.txt
		std::fclose(file_handle);

		// re-throw the exception we just caught
		throw;
	}

	// manually close logfile.txt 
	std::fclose(file_handle);
}

