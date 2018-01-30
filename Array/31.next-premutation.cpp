// Time: O(n), Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) --i;
        if (i > 0) {
            --i; // find the stop position of ascending order from back
            int j = nums.size() - 1;
            while (j > 0 && nums[j] <= nums[i]) --j;    // find the next bigger number behind the stop position
            // swap and reorder back part
            swap(nums[i], nums[j]);
            if (nums.size() > 1) reverse(nums, i + 1, nums.size() - 1);
        } 
        else {
            reverse(nums, 0, nums.size() - 1);
            return;
        }
    }
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            ++begin;
            --end;
        }
    }
};