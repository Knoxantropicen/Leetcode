// Time: O(m*n), Space: O(min(m,n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        int r, c;
        (m < n) ? (r = n, c = m) : (r = m, c = n);
        vector<int> path(c, 1);	// represent one row
        for (int i = 1; i < r; ++i)
            for (int j = 1; j < c; ++j)
                path[j] += path[j - 1];	// = add upper and left number together
        return path[c - 1];
    }
};