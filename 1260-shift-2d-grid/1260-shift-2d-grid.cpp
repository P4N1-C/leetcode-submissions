class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        while(k--) {
            for(int i = 0; i < n; i++) {
                for(int j = m - 1; j >= 1; j--) {
                    swap(grid[i][j], grid[i][j - 1]);
                }
            }
            for(int i = n - 1; i >= 1; i--) {
                swap(grid[i][0], grid[i - 1][0]);
            }
        }
        return grid;
    }
};