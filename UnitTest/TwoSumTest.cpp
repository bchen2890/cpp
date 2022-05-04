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

		TEST_METHOD(Case1)
		{
			vector<int> nums { 2,7,11,15 };
			int target = 9;
			checkSum(nums, target);
		}
		TEST_METHOD(Case2)
		{
			vector<int> nums{ 3,2,4 };
			int target = 6;
			checkSum(nums, target);
		}
		TEST_METHOD(Case3)
		{
			vector<int> nums{1,3,3};
			int target = 6;
			checkSum(nums, target);
		}
		void checkSum(vector<int>& nums, int target) {
			TwoSum twoSum;
			vector<int> sol = twoSum.solutionBruteForce(nums, target);
			Assert::AreEqual(target, nums[sol[0]] + nums[sol[1]]);
			sol = twoSum.solutionMap(nums, target);
			Assert::AreEqual(target, nums[sol[0]] + nums[sol[1]]);
		}
	};


}
