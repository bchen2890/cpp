#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../LeetCodeProblem/BestTimeToBuyAndSellStock.cpp"

using std::vector;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BestTimeToBuyAndSellStockTest
{
	TEST_CLASS(BestTimeToBuyAndSellStockTest)
	{
	public:

		TEST_METHOD(Case1)
		{
			vector<int> prices{ 7,1,5,3,6,4 };
			int max = 5;
			checkMax(prices, max);
		}
		TEST_METHOD(Case2)
		{
			vector<int> prices{ 7,6,4,3,1 };
			int max = 0;
			checkMax(prices, max);
		}
		TEST_METHOD(Case3)
		{
			vector<int> prices{ 7,4,5,6,4,2,1,5 };
			int max = 4;
			checkMax(prices, max);
		}
		void checkMax(vector<int>& prices, int max) {
			BestTimeToBuyAndSellStock maxProfit;
			int sol = maxProfit.solutionBruteForce(prices);
			Assert::AreEqual(max, sol);
		}
	};


}
