// Time: O(n^2), Space: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // get upper-left 1/4 block
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n - n / 2; ++j) {
                int temp = matrix[i][j];
                // exchange 4 corresponding elements
                for (int k = 0; k < 4; ++k) {
                    if (k == 3) matrix[i][j] = temp;
                    else matrix[i][j] = matrix[n - j - 1][i];
                    int p = i;
                    i = n - j - 1;
                    j = p;
                }
            }
        }
    }
};