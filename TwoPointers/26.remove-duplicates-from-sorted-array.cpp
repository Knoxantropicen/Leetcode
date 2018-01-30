// Time: O(n), Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[prev]) continue;
            // find 1st non-duplicate number
            nums[++prev] = nums[i];
        }
        int final_size = nums.empty() ? 0 : prev + 1;
        nums.resize(final_size);
        return final_size;
    }
};