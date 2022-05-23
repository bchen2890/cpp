#include <vector>
#include <unordered_map>
#include<algorithm>

using std::vector;

/**
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * @param nums an array of integers.
 * @return an array answer such that answer[i] is equal to the product
 *          of all the elements of nums except nums[i].
 */
class ProductOfArrayExceptSelf{
public:
    vector<int> solution(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix = vector<int>(n), answer = vector<int>(n);
        int left = 1 , right = 1;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = right;
            right *= nums[i];
        };
        for (int i = 0; i != nums.size(); i++) {
            answer[i] = left * suffix[i];
            left *= nums[i];
        };
        return answer;
    }
};