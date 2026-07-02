class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        q.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        while(!q.empty()) {
            auto [h, x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if(dist[nx][ny] > h + grid[nx][ny]) {
                        dist[nx][ny] = h + grid[nx][ny];
                        q.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
        return dist[m - 1][ n- 1] < health;
    }
};