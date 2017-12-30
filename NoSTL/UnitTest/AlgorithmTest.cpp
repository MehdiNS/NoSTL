#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NoSTL/Algorithm.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNoSTL
{
	TEST_CLASS(TestAlgorithm)
	{
	public:

		TEST_METHOD(TestCopy)
		{
			{
				std::vector<int> emptyV{};
				std::vector<int> newV1{};
				std::vector<int> newV2{};

				nostd::copy(emptyV.begin(), emptyV.end(), newV1.begin());
				std::copy(emptyV.begin(), emptyV.end(), newV2.begin());
				Assert::AreEqual(std::equal(newV1.begin(), newV1.end(), newV2.begin(), newV2.end()), true);
			}

			{
				int myints[] = { 1,2,3,4,5,6,7 };
				std::vector<int> myvector(7);
				nostd::copy(myints, myints + 7, myvector.begin());
				Assert::AreEqual(std::equal(myints, myints+7, myvector.begin(), myvector.end()), true);
			}
		}

		TEST_METHOD(TestSwap)
		{
			int x = 10;
			int y = 0;
			nostd::swap(x, y);
			Assert::AreEqual(x == 0 && y == 10, true);

			std::vector<int> vec1 = {1, 2, 3, 4};
			std::vector<int> vec2 = {4, 3, 2, 1};
			nostd::swap(vec1, vec2);
			Assert::AreEqual(vec1[0] + vec2[0], 5);
		}
	};
}