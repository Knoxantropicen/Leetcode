// Time: O(m*n), Space: O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') continue;
                // start search
                DFS(grid, i, j);
                ++count;
            }
        }
        return count;
    }
    void DFS(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        // left
        if (j > 0 && grid[i][j - 1] == '1') DFS(grid, i, j - 1);
        // right
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') DFS(grid, i, j + 1);
        // up
        if (i > 0 && grid[i - 1][j] == '1') DFS(grid, i - 1, j);
        // down
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') DFS(grid, i + 1, j);
    }
};

// Time: O(m*n), Space: O(min(m,n))
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') continue;
                // start search
                queue<vector<int>> coordList;
                grid[i][j] = '0';
                coordList.push({i, j});
                while (!coordList.empty()) {
                    vector<int> c = coordList.front();
                    coordList.pop();
                    int x = c[0], y = c[1];
                    if (x > 0 && grid[x - 1][y] == '1') { grid[x - 1][y] = '0'; coordList.push({x - 1, y}); }
                    if (y > 0 && grid[x][y - 1] == '1') { grid[x][y - 1] = '0'; coordList.push({x, y - 1}); }
                    if (y < grid[0].size() - 1 && grid[x][y + 1] == '1') { grid[x][y + 1] = '0'; coordList.push({x, y + 1}); }
                    if (x < grid.size() - 1 && grid[x + 1][y] == '1') { grid[x + 1][y] = '0'; coordList.push({x + 1, y}); }
                }
                ++count;
            }
        }
        return count;
    }
};