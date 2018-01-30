// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1, temp_sum;
        while (left < right) {
            temp_sum = numbers[left] + numbers[right];
            if (temp_sum == target) {
                return vector<int>{left + 1, right + 1};
            }
            if (temp_sum > target) {
                --right;
            } else {
                ++left;
            }
        }
    }
};