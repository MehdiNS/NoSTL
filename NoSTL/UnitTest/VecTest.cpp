#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NoSTL/Vec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNoSTL
{
	TEST_CLASS(TestVector3)
	{
	public:

		TEST_METHOD(TestVector3CommonUse)
		{
			nostd::vec3 v0{ 1.f, 0.f, 0.f };
			Assert::AreEqual(nostd::length(v0), 1.f);
			Assert::AreEqual(nostd::normalize(v0) == v0, true);
		}
	};
}