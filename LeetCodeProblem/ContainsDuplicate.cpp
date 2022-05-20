#include <vector>
#include <unordered_map>
#include<algorithm>

using std::vector;

/**
 * @param nums an array of integers
 * @return true if any value appears at least twice in the array, and false if every element is distinct
 */

class ContainsDuplicate {
public:
    /**
     * Brute-force Optimized Solution. Complexity O(n^2). Not accepted because of Time Limit Exceeded.
     */
    bool solutionBruteForce(vector<int>& nums) {
        for (int i = 0; i != nums.size(); i++) 
            for (int j = i+1 ; j < nums.size(); j++) 
                if (nums[i] == nums[j])
                    return true;
        return false;
    }

    /**
     * SortBefore Solution. Complexity O(n·log(n))
     */
    bool solutionSortBefore(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i != nums.size(); i++)
                if (nums[i] == nums[i-1])
                    return true;
        return false;
    }
};