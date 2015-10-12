#include "Arguments.h"
#include "gtest/gtest.h"
#include <string>

//=============================================================================
TEST (constructortest, TestAppName)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	Arguments args1(argc, argv);
    ASSERT_EQ(argv[0], args1.appName());
}
//=============================================================================
TEST (count, TestCount)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	Arguments args1(argc, argv);
	ASSERT_EQ(2, args1.count());
}
//=============================================================================
TEST (copyconstructor, TestCopyConstructor)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	Arguments args1(argc, argv);
	Arguments args2(args1);	
	ASSERT_EQ(args1.appName(), args2.appName());
	
	for (int i = 0; i < (argc-1); i++)
	{
		ASSERT_EQ(args1[i], args2[i]);
	}
}
//=============================================================================
TEST (assignmentop, TestAssignmentOp)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	Arguments args1(argc, argv);
	Arguments args2(argc, argv);
	args1 = args2;
	
	ASSERT_EQ(args1.appName(), args2.appName());
	
	for (int i = 0; i < (argc-1); i++)
	{
		ASSERT_EQ(args1[i], args2[i]);
	}	
}
//=============================================================================
TEST (subscriptop, TestSubscriptOp)
{
	const int argc = 3;
	char *argv[argc] = {(char*) "main", (char*) "abc", (char*) "12"};
	Arguments args1(argc, argv);

	for (int i = 0; i < (argc-1); i++)
	{
		ASSERT_EQ(argv[i+1], args1[i]);
	}
}
