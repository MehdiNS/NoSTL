#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NoSTL/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNoSTL
{
	TEST_CLASS(TestVector)
	{
	public:

		TEST_METHOD(TestVectorCreation)
		{
			nostd::vector<int> v0{};
			Assert::AreEqual(v0.capacity() == 0 && v0.size() == 0, true);

			nostd::vector<int> v1{ 16, 42 };
			Assert::AreEqual(v1.capacity() == 16 && v1.size() == 16 && v1[v1.size()-1] == 42, true);

			nostd::vector<int> v2{ v1 };
			Assert::AreEqual(v2.capacity() == 16 && v2.size() == 16 && v2[v2.size() - 1] == 42, true);
		}

		TEST_METHOD(TestVectorPushBackAndGrow)
		{
			nostd::vector<int> v0{};
			v0.push_back(0);
			Assert::AreEqual(v0.size(), 1);
			Assert::AreEqual(v0.capacity(), 1);
			v0.push_back(1);
			Assert::AreEqual(v0.size(), 2);
			Assert::AreEqual(v0.capacity(), 2);
			v0.push_back(2);
			Assert::AreEqual(v0.size(), 3);
			Assert::AreEqual(v0.capacity(), 4);
		}

		TEST_METHOD(TestVectorCompare)
		{
			nostd::vector<int> v0{ 16, 42 };
			nostd::vector<int> v1{ 16, 42 };
			nostd::vector<int> v2{ 16, 43 };
			nostd::vector<int> v3{ 8, 42 };

			Assert::AreEqual(v0 == v1, true);
			Assert::AreEqual(v0 != v2, true);
			Assert::AreEqual(v0 != v3, true);
		}
	};
}