// Time: O(n), Space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int first = 0, curr = 0; curr < nums.size(); ++curr)
            if (nums[curr] != 0)  swap(nums[first++], nums[curr]);
    }
};