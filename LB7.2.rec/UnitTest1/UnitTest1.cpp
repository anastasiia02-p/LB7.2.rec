#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.2.rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 5; a[0][2] = 9;
			a[1][0] = 3; a[1][1] = 7; a[1][2] = 2;
			a[2][0] = 4; a[2][1] = 8; a[2][2] = 6;

			int minOfMax = INT_MAX;
			findMinOfMaxInOddColumns(a, rowCount, colCount, 1, minOfMax);
			Assert::AreEqual(2147483647, minOfMax);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
