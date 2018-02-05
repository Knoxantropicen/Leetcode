// Time: O(n), Space: O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (auto ch: s) {
            sum += sum * 25 + ch - 64;
        }
        return sum;
    }
};