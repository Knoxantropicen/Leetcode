// Time: O(n), Space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev[2] = {1, 1};
        for (int i = 2; i <= n; ++i) {
            prev[i & 1] = prev[i & 1] + prev[(i - 1) & 1];
        }
        return prev[n & 1];
    }
};