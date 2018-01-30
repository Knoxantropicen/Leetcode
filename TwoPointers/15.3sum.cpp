// Time: O(n^2), Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();  // invalid
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // exclude duplicate
            int first = nums[i];
            int two_sum = -first;
            // find a + b == two_sum in subsequent array
            // j ---> <--- k
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int curr_sum = nums[j] + nums[k];
                if (curr_sum == two_sum) {          // equal
                    int second = nums[j], third = nums[k];
                    vector<int> pair = {first, second, third};
                    result.push_back(pair);
                    while (j < k && nums[j] == second) ++j; // exclude duplicate
                    while (j < k && nums[k] == third) --k;
                } else if (curr_sum > two_sum) {    // big
                    --k;
                } else {                            // small
                    ++j;
                }
            }
        }
        return result;
    }
};