// Time: O(n*log(n)), Space: O(log(n))
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int big[3], small[2];
        // make maximum heap
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < 3; ++i) {
            big[i] = nums.front();
            pop_heap(nums.begin(), nums.end() - i);
        }
        // make minimum heap
        make_heap(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < 2; ++i) {
            small[i] = nums.front();
            pop_heap(nums.begin(), nums.end() - i, greater<int>());
        }
        return max(big[0] * big[1] * big[2], big[0] * small[0] * small[1]);
    }
};