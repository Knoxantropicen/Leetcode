// Time: O(n), Space: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t dup_count = 0, n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            if (nums[i] == val) ++dup_count;
            else nums[i - dup_count] = nums[i];
        }
        nums.resize(n - dup_count);
        return n - dup_count;
    }
};