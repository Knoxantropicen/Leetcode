// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 0-8, 9, 10-18, 19, 99, ...
        int n = digits.size();
        int first_9 = n - 1;    // find position of the first 9 (from begin to end)
        while (first_9 >= 0 && digits[first_9] == 9) --first_9;
        ++first_9;
        if (first_9 == n) { // not ended with 9
            digits[n - 1] += 1;
        } else {    // ended with 9s
            for (int i = first_9; i < n; ++i) digits[i] = 0;
            if (digits[0] == 0) digits.insert(digits.begin(), 1);   // all 9s
            else digits[first_9 - 1] += 1;
        }
        return digits;
    }
};