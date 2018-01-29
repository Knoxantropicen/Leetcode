// Time: O(n), Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ideal_sum = n * (n+1) / 2;
        int actual_sum = 0;
        for (int i=0; i<n; ++i) {
            actual_sum += nums[i];
        }
        return ideal_sum - actual_sum;
    }
};