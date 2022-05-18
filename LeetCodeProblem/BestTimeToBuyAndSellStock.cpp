#include <vector>
#include <unordered_map>
#include<algorithm>

using std::vector;

/**
 * @param prices an array of integers where prices[i] is the price of a given stock on the i_th day.
 * @return an integer so that it's the maximum profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 *          If there is not any profit, it returns 0.
 */
class BestTimeToBuyAndSellStock {
public:
    /**
     * Brute-force Optimized Solution. Complexity O(n^2)
     */
    int solutionBruteForce(vector<int>& nums) {
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i != nums.size(); i++) {
            min = std::min(min, nums[i]);
            max = std::max(max, nums[i] - min);
        }
        return max;
    }
};