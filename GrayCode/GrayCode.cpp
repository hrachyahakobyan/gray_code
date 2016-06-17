// GProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gray_code.h"


int _tmain(int argc, _TCHAR* argv[])
{
	gray_code<4> gray_from_int = gray_code<4>::from_integer(6);
	gray_from_int.print_binary();
	gray_from_int.print_gray();

	gray_code<4> gray_from_string = gray_code<4>::from_string("0001110");
	gray_from_string.print_binary();
	gray_from_string.print_gray();

	gray_code<4> gray_from_binary = gray_code<4>::from_binary(std::bitset<4>("0110"));
	gray_from_binary.print_binary();
	gray_from_binary.print_gray();

	auto gc5 = gray_from_binary.increment();
	gc5.print_binary();
	gc5.print_gray();
	return 0;
}

