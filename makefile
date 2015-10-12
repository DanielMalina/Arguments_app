RM = rm

CPPTOOL = g++
CPPFLAGS = -Wall

CPP = $(CPPTOOL) $(CPPFLAGS) -c
LINK = $(CPPTOOL) -o

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

test: test.exe
	test.exe
	
	
test.exe: test.o Arguments.o test_Exceptions.o $(GTEST_LIB)
	$(LINK) test.exe test.o test_Exceptions.o Arguments.o $(GTEST_LIB)

test.o: test.cpp Arguments.h
	$(CPP) test.cpp $(GTEST_INC)
	
test_Exceptions.o: test_Exceptions.cpp Arguments.h
	$(CPP) test_Exceptions.cpp $(GTEST_INC)
		
all: main.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o

main.o: main.cpp Arguments.h
	$(CPP) main.cpp

Arguments.o: Arguments.cpp Arguments.h
	$(CPP) Arguments.cpp

clean:
	$(RM) Arguments.o
	$(RM) test.o
	$(RM) test_Exceptions.o
	$(RM) test.exe
	$(RM) main.exe
	$(RM) main.o
	
	
