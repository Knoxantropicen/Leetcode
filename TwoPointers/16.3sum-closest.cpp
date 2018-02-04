// Time: O(n^2), Space: O(log(n))
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int first = nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int second = nums[j], third = nums[k];
                int sum = first + second + third;
                int distance = abs(sum - target);
                if (distance < closest) {
                    result = sum;
                    closest = distance;
                }
                if (sum == target) return target;
                else if (sum > target) --k;
                else ++j;
            }
        }
        return result;
    }
};