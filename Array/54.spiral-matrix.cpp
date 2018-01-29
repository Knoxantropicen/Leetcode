// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int i = 0, j = 0;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (true) {
            while (j <= r) result.push_back(matrix[i][j++]);
            ++u; --j; ++i;
            if (u > d) break;
            while (i <= d) result.push_back(matrix[i++][j]);
            --r; --i; --j;
            if (l > r) break;
            while (j >= l) result.push_back(matrix[i][j--]);
            --d; ++j; --i;
            if (u > d) break;
            while (i >= u) result.push_back(matrix[i--][j]);
            ++l; ++i; ++j;
            if (l > r) break;
        }
        return result;
    }
};