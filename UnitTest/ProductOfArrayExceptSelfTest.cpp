#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../LeetCodeProblem/ProductOfArrayExceptSelf.cpp"

using std::vector;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProductOfArrayExceptSelfTest
{
	TEST_CLASS(ProductOfArrayExceptSelfTest)
	{
	public:

		TEST_METHOD(Case1)
		{
			vector<int> nums{ 1,2,3,4 };
			vector<int> expected{ 24,12,8,6 };
			checkProduct(nums, expected);
		}

		TEST_METHOD(Case2)
		{
			vector<int> nums{ -1,1,0,-3,3 };
			vector<int> expected{ 0,0,9,0,0 };
			checkProduct(nums, expected);
		}

		void checkProduct(vector<int>& nums, vector<int>& expected) {
			ProductOfArrayExceptSelf product;
			vector<int> sol = product.solution(nums);
			Assert::IsTrue(expected == sol);
		}
	};


}
