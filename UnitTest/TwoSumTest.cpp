#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../LeetCodeProblem/TwoSum.cpp"

using std::vector;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TwoSumTest
{
	TEST_CLASS(TwoSumTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<int> nums { 2,7,11,15 };
			int target = 9;
			TwoSum twoSum;
			vector<int> sol = twoSum.solution(nums,target);
			Assert::AreEqual(target, nums[sol[0]] + nums[sol[1]]);
		}
	};
}
