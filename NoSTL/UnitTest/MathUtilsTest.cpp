#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NoSTL/MathUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNoSTL
{
	TEST_CLASS(TestMathUtils)
	{
	public:

		TEST_METHOD(TestMax)
		{
			Assert::AreEqual(nostd::max<int>(1, 5), 5);
			Assert::AreEqual(nostd::max<int>(5, 1), 5);
			Assert::AreEqual(nostd::max<int>(0, 0), 0);
			Assert::AreEqual(nostd::max<int>(-1, 5), 5);
			Assert::AreEqual(nostd::max<int>(-5, -1), -1);

			Assert::AreEqual(nostd::max<float>(1.f, 5.f), 5.f);
			Assert::AreEqual(nostd::max<float>(5.f, 1.f), 5.f);
			Assert::AreEqual(nostd::max<float>(0.f, 0.f), 0.f);
			Assert::AreEqual(nostd::max<float>(-1.f, 5.f), 5.f);
			Assert::AreEqual(nostd::max<float>(-5.f, -1.f), -1.f);
		}

		TEST_METHOD(TestMin)
		{
			Assert::AreEqual(nostd::min<int>(1, 5), 1);
			Assert::AreEqual(nostd::min<int>(5, 1), 1);
			Assert::AreEqual(nostd::min<int>(0, 0), 0);
			Assert::AreEqual(nostd::min<int>(-1, 5), -1);
			Assert::AreEqual(nostd::min<int>(-5, -1), -5);

			Assert::AreEqual(nostd::min<float>(1.f, 5.f), 1.f);
			Assert::AreEqual(nostd::min<float>(5.f, 1.f), 1.f);
			Assert::AreEqual(nostd::min<float>(0.f, 0.f), 0.f);
			Assert::AreEqual(nostd::min<float>(-1.f, 5.f), -1.f);
			Assert::AreEqual(nostd::min<float>(-5.f, -1.f), -5.f);
		}

		TEST_METHOD(TestClamp)
		{
			Assert::AreEqual(nostd::clamp<int>(42, 42, 42), 42);
			Assert::AreEqual(nostd::clamp<int>(1, 5, 10), 5);
			Assert::AreEqual(nostd::clamp<int>(7, 5, 10), 7);
			Assert::AreEqual(nostd::clamp<int>(11, 5, 10), 10);
			Assert::AreEqual(nostd::clamp<int>(10, -1, 1), 1);
			Assert::AreEqual(nostd::clamp<int>(0, -1, 1), 0);
			Assert::AreEqual(nostd::clamp<int>(1, -1, 1), 1);

			Assert::AreEqual(nostd::clamp<float>(42.f, 42.f, 42.f), 42.f);
			Assert::AreEqual(nostd::clamp<float>(1.f, 5.f, 10.f), 5.f);
			Assert::AreEqual(nostd::clamp<float>(7.f, 5.f, 10.f), 7.f);
			Assert::AreEqual(nostd::clamp<float>(11.f, 5.f, 10.f), 10.f);
			Assert::AreEqual(nostd::clamp<float>(10.f, -1.f, 1.f), 1.f);
			Assert::AreEqual(nostd::clamp<float>(0.f, -1.f, 1.f), 0.f);
			Assert::AreEqual(nostd::clamp<float>(1.f, -1.f, 1.f), 1.f);
		}

		TEST_METHOD(TestSaturate)
		{
			Assert::AreEqual(nostd::saturate<int>(-1), 0);
			Assert::AreEqual(nostd::saturate<int>(0), 0);
			Assert::AreEqual(nostd::saturate<int>(1), 1);
			Assert::AreEqual(nostd::saturate<int>(2), 1);

			Assert::AreEqual(nostd::saturate<float>(-1.f), 0.f);
			Assert::AreEqual(nostd::saturate<float>(0.f), 0.f);
			Assert::AreEqual(nostd::saturate<float>(0.5f), 0.5f);
			Assert::AreEqual(nostd::saturate<float>(1.1f), 1.f);
		}
	};
}