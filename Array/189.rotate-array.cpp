// Time: O(n), Space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kr = k % n;
        for (int begin = 0, cnt = 0; cnt < n; ++begin) {
            int curr = begin, next, temp;
            int prev = nums[begin];
            do {
                // find next, fill next with prev, continue finding next, until back to begin
                next = (curr + kr) % n;
                temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                ++cnt;
            } while (next != begin);
        }
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int kr = k % n;
        // reverse three times ([0, n), [0, k), [k, n))
        reverse(nums, 0, n - 1);
        reverse(nums, 0, kr - 1);
        reverse(nums, kr, n - 1);
    }
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            ++begin;
            --end;
        }
    }
};