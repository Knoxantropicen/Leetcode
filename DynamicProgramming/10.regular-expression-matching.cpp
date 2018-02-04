// Time: O(n_s*n_p), Space: O(n_s)
class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length(), len_p = p.length(), len_c = len_s + 1;
        vector<bool> cursor(len_c, false);
        cursor[0] = true;
        for (int i = 0; i < len_p; ++i) {
            // with * postfix
            if (i != len_p - 1 && p[i + 1] == '*') {
                // .*
                if (p[i] == '.') {
                    // mark whole future as true
                    int j = 0;
                    while (j < len_c && !cursor[j]) ++j;
                    if (j < len_c) {    // find min true cursor
                        for (int k = j + 1; k < len_c; ++k) cursor[k] = true;
                    }
                }
                // a*
                else {
                    // mark future with consequtive 'a' as true
                    for (int j = 1; j < len_c; ++j) {
                        if (!cursor[j - 1]) continue;
                        while (j < len_c && s[j - 1] == p[i]) cursor[j++] = true;
                    }
                }
                ++i;
            }
            // without * postfix
            else {
                cursor.back() = false;
                // .
                if (p[i] == '.') {
                    // mark all curr as false, all next as true
                    for (int j = len_c - 1; j >= 1; --j) {
                        if (!cursor[j - 1]) continue;
                        cursor[j] = true;
                        cursor[j - 1] = false;
                    }
                }
                // a
                else {
                    // mark all curr as false, all next with 'a' as true
                    for (int j = len_c - 1; j >= 1; --j) {
                        if (!cursor[j - 1]) continue;
                        if (s[j - 1] == p[i]) {
                            cursor[j] = true;
                            cursor[j - 1] = false;
                        }
                        else {
                            cursor[j - 1] = false;
                        }
                    }
                }
            }
        }
        return cursor.back();
    }
};