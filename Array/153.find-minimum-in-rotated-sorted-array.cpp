// Time: O(log(n)), Space: O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {   // right side
                left = mid + 1;
            }
            else {  // left side
                right = mid;
            }
        }
        return nums[left];
    }
};