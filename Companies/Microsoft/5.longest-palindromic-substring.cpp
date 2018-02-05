// Time: O(n^2), Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return s;
        int longest = 1, left = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == s[i]) {
                findPalindrome(s, longest, left, i - 1, i);
            }
            if (i < s.length() - 1 && s[i - 1] == s[i + 1]) {
                findPalindrome(s, longest, left, i - 1, i + 1);
            }
        }
        return s.substr(left, longest);
    }
    void findPalindrome(string& s, int& longest, int &left, int l, int r) {
    	while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
        }
        int len = r - l - 1;
        if (len > longest) {
            longest = len;
            left = l + 1;
        }
    }
};