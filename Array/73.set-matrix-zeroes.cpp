// Time: O(n^2), Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // check if first column has 0
        bool first_col_zero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }
        // first colomn represents if each row has 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        // set columns to 0
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < m; ++k) matrix[k][j] = 0;
                    break;
                }
            }   
        }
        // set rows to 0
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) matrix[i][j] = 0;
            }
        }
        // set first column to 0 if it has 0
        if (first_col_zero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};