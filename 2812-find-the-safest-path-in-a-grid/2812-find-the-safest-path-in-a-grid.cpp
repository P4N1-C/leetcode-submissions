class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        map<pair<int, int>, int> mp;
        queue<tuple<int, int,int>> q;
        int dx[] = {1 ,-1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[{i, j}] = -1;
                if (grid[i][j] == 1) {
                    mp[{i, j}] = 0;
                    q.push({0, i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    mp[{nx, ny}] == -1) {
                    mp[{nx, ny}] = d + 1;
                    q.push({d + 1, nx, ny});
                }
            }
        }
        priority_queue<vector<int>> pq;
        pq.push({mp[{0, 0}], 0, 0});
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = mp[{0, 0}];
        while(!pq.empty()) {
            auto it = pq.top();pq.pop();
            int wt = it[0], x = it[1], y = it[2];
            if(x == n - 1 && y == n - 1) return wt;
            if(dist[x][y] > wt) continue;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int curr = min(wt, mp[{nx, ny}]);
                    if(curr > dist[nx][ny]) {
                        dist[nx][ny] = curr;
                        pq.push({curr, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};