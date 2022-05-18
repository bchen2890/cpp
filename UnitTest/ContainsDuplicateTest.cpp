#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../LeetCodeProblem/ContainsDuplicate.cpp"

using std::vector;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ContainsDuplicateTest
{
	TEST_CLASS(ContainsDuplicateTest)
	{
	public:

		TEST_METHOD(Case1)
		{
			vector<int> nums{ 1,2,3,1 };
			bool expected = true;
			checkDuplicate(nums, expected);
		}
		TEST_METHOD(Case2)
		{
			vector<int> nums{ 1,2,3,4 };
			bool expected = false;
			checkDuplicate(nums, expected);
		}
		TEST_METHOD(Case3)
		{
			vector<int> nums{ 1,1,1,3,3,4,3,2,4,2 };
			bool expected = true;
			checkDuplicate(nums, expected);
		}
		void checkDuplicate(vector<int>& nums, bool expected) {
			ContainsDuplicate  duplicate;
			bool sol = duplicate.solutionBruteForce(nums);
			Assert::AreEqual(expected, sol);
		}
	};


}
