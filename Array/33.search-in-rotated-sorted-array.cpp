// Time: O(log(n)), Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            // judge if is inside a sequenced array
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {    // low <= target
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {   // target <= high
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            // make sure low > high never happens
        }
        return -1;
    }
};