// Time: O(n), Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore voting algorithm
        int major = nums[0], count = 0;
        for (int i=0; i<nums.size(); ++i) {
            nums[i] == major ? ++count : --count;
            if (count == 0) {
                major = nums[i];
                ++count;
            }
        }
        return major;
    }
}