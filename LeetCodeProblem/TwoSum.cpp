#include <vector>
using std::vector;

class TwoSum {
public:
    vector<int> solution(vector<int>& nums, int target) {
        vector<int> sol(2);
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i+1; j != nums.size(); ++j) {
                if (nums[i] == target - nums[j]) {
                    sol = { i,j };
                    break;
                }
            }
        }
        return sol;
    }
};