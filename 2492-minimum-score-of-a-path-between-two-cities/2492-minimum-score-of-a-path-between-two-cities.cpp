class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> visi(n + 1, false);
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            if(visi[curr]) continue;
            visi[curr] = true;
            for(auto [node, cost] : adj[curr]) {
                ans = min(ans, cost);
                q.push(node);
            }
        }
        return ans;
    }
};