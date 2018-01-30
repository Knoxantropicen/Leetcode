// Time: O(n*t), Space: O(t)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target + 1);
        result[0] = 1;
        // calculate result[i] in order from 1 to target
        for (int i = 1; i <= target; ++i) {
            for (int num: nums) {
                if (i >= num) result[i] += result[i - num]; // calculate current num based on previous num
            }
        }
        return result[target];
    }
};