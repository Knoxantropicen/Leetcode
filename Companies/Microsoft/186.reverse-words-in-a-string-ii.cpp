// Time: O(n), Space: O(1)
class Solution {
public:
    void reverseWords(vector<char>& str) {
        // reverse all
        reverse(str, 0, str.size() - 1);
        // reverse by word
        int left = 0;
        for (int right = 0; right < str.size(); ++right) {
            if (str[right] == ' ') {
                reverse(str, left, right - 1);
                left = right + 1;
            }
        }
        reverse(str, left, str.size() - 1);
    }
    void reverse(vector<char>& str, int left, int right) {
        for (; left < right; (++left, --right)) swap(str[left], str[right]);
    }
};