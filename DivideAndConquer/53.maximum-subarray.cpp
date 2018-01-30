// Time: O(n), Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for (auto x: nums) {
            sum += x;
            ans = max(ans, sum); // check current sum
            sum = max(sum, 0);	// can discard previous sum
        }
        return ans;
    }
};