// Time: O(n^2), Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return vector<vector<int>>();
        vector<vector<int>> result(n, vector<int>(n));
        int i = 0, j = 0;
        int u = 0, d = n - 1, l = 0, r = n - 1;
        int num = 1;
        while (true) {
            while (j <= r) result[i][j++] = num++;
            ++u; --j; ++i;
            if (u > d) break;
            while (i <= d) result[i++][j] = num++;
            --r; --i; --j;
            if (l > r) break;
            while (j >= l) result[i][j--] = num++;
            --d; ++j; --i;
            if (u > d) break;
            while (i >= u) result[i--][j] = num++;
            ++l; ++i; ++j;
            if (l > r) break;
        }
        return result;
    }
};