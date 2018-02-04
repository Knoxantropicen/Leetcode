// Time: O(n), Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int reach = 0, n = nums.size() - 1; // record the furthest position can be reached
        for (int i = 0; i <= min(reach, n); ++i) {
            reach = max(i + nums[i], reach);
        }
        return reach >= n;
    }
};