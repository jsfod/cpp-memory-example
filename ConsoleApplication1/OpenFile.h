#pragma once

// Taken from : https://en.wikibooks.org/wiki/C%2B%2B_Programming/RAII

#include <cstdio>
#include <stdio.h>

// exceptions
class file_error { };
class open_error : public file_error { };
class close_error : public file_error { };
class write_error : public file_error { };

class file
{
public:
	file(const char* filename)
	{
		errno_t err;
		//m_file_handle(std::fopen(filename, "w+"))
		err = fopen_s(&m_file_handle, filename, "w+");
		if (m_file_handle == NULL)
		{
			throw open_error();
		}
	}

	~file()
	{
		std::fclose(m_file_handle);
	}

	void write(const char* str)
	{
		if (std::fputs(str, m_file_handle) == EOF)
		{
			throw write_error();
		}
	}

	void write(const char* buffer, std::size_t num_chars)
	{
		if (num_chars != 0
			&&
			std::fwrite(buffer, num_chars, 1, m_file_handle) == 0)
		{
			throw write_error();
		}
	}

private:
	std::FILE* m_file_handle;

	// copy and assignment not implemented; prevent their use by
	// declaring private.
	file(const file &);
	file & operator=(const file &);
};
