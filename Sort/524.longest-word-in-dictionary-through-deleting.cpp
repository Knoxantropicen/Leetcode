// Time: O(n_s*n_d), Space: O(1)
bool comp(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return s1.length() < s2.length();
    else return s1 > s2;
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        make_heap(d.begin(), d.end(), comp);
        while (d.begin() != d.end()) {
            string word = d.front();
            if (s.length() < word.length()) continue;
            int j = 0;
            for (int i = 0; i < s.length() && j < word.length(); ++i) {
                if (s[i] == word[j]) ++j;
            }
            if (j == word.length()) return word;
            pop_heap(d.begin(), --d.end(), comp);
        }
        return "";
    }
};