#include <vector>
#include <unordered_map>

using std::vector;

/**
 * @param nums an array of integers
 * @param target a integer
 * @return {i,j} so that nums[i]+nums[j]==target and i!=j.
 */
class TwoSum {
public:
    /**
     * Brute-force Solution. Complexity O(n^2)
     */

    vector<int> solutionBruteForce(vector<int>& nums, int target) {
        vector<int> sol(2);
        for (int i = 0; i != nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == target - nums[j]) {
                    sol = { i,j };
                    break;
                }
            }
        }
        return sol;
    }

    /**
     * Map Solution. Complexity O(n)
     */
    vector<int> solutionMap(vector<int>& nums, int target) {
        vector<int> sol(2);
         std::unordered_map<int,int> numsMap;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (numsMap.count(diff)>0) {
                sol = { i, numsMap[diff] };
                break;
            }
            numsMap[nums[i]] = i;
        }
        return sol;
    }
};