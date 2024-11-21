#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab11.4/Lab11.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream testFile("test.txt");
			testFile << "Toyota 20000 150\n";
			testFile << "Honda 18000 200\n";
			testFile << "Ford 22000 250\n";
			testFile.close();

			ifstream inFile("test.txt");
			double expectedAverage = (150 + 200 + 250) / 3.0;
			double actualAverage = calculateAverageMileage(inFile);
			inFile.close();

			Assert::AreEqual(expectedAverage, actualAverage, 0.001, L"Неправильний середній кілометраж");
		}
	};
}
