// Time: O(n_x+n_y), Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        // start from bottom-left, if target is greater -> move right, if target is less -> move up
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) ++j;
            else --i;
        }
        return false;
    }
};

// Time: O(n_y*log(n_x)), Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; 
        // find left row range
        int top = findRow(matrix, target, 0);
        if (top == -1 || matrix[top].front() == target) return true;
        int left = (matrix[top].front() > target) ? top - 1 : top;
        if (left < 0) return false;
        // find right row range
        top = findRow(matrix, target, matrix[0].size() - 1);
        if (top == -1 || matrix[top].back() == target) return true;
        int right = (matrix[top].back() < target) ? top + 1 : top;
        if (right > matrix[0].size() - 1) return false;
        // find col range
        for (int i = right; i <= left; ++i) {
            int pos = findCol(matrix, target, i);
            if (pos == -1 || matrix[i][pos] == target) return true;
        }
        return false;
    }
    int findRow(vector<vector<int>>& matrix, int target, int col) {
        int top = 0, bottom = matrix.size() - 1, mid;
        while (top < bottom) {
            mid = (top + bottom) / 2;
            if (matrix[mid][col] == target) return -1;  // find target
            if (matrix[mid][col] < target) top = mid + 1;
            else bottom = mid;
        }
        return top;
    }
    int findCol(vector<vector<int>>& matrix, int target, int row) {
        int left = 0, right = matrix[0].size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (matrix[row][mid] == target) return -1;  // find target
            if (matrix[row][mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};