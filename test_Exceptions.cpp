#include "Arguments.h"
#include "gtest/gtest.h"
#include <string>


//=============================================================================
//TEST :Throws exception (int) if argc < 1 or argv == 0.
// argc == 0
TEST (zeroargumentException, TestZeroArgumentValue)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	bool hasException = false;
	
	try
	{
		int argc = 0;
		char *argv[argc];
		Arguments args1(argc, argv);
	}
	catch (int e)
	{
		hasException = true;
	}
	EXPECT_EQ(true, hasException);
}
//=============================================================================
//TEST :Throws exception (int) if argc < 1 or argv == 0.
// argc < 0
TEST (negativeArgException, TestNegArgumentsValue)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	bool hasException = false;
	
	try
	{
		int argc = -1;
		char *argv[argc];
		Arguments args1(argc, argv);
	}
	catch (int e)
	{
		hasException = true;
	}
	EXPECT_EQ(true, hasException);
}

//=============================================================================
//TEST :Throws exception (int) if argc < 1 or argv == 0.
//argv == 0;
TEST (noargumentsException, TestNoArguments)
{
	const int argc = 3;
	char **argv = 0;
	bool hasException = false;
	
	try
	{	
		Arguments args1(argc, argv);
	}
	catch (int e)
	{
		hasException = true;
	}
	EXPECT_EQ(true, hasException);
}
//=============================================================================
//Throws exception (size_t) if index is out of range
TEST (subscriptException, TestSubscriptException)
{
	
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	bool hasException = false;
	Arguments args1(argc, argv);
	try
	{
		std :: string str = args1 [argc + 1];
	}
	catch (size_t e)
	{
		hasException = true;
	}
	EXPECT_EQ(true, hasException);
}
