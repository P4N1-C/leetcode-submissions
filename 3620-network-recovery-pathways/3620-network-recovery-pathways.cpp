class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges) {
            int u = it[0], v = it[1], cost = it[2];
            adj[u].push_back({v, cost});
        }
        long long low = 0, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            vector<long long> dist(n, 1e18); 
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[0] = 0;
            pq.push({0, 0});
            while(!pq.empty()) {
                auto [cost, curr] = pq.top();
                pq.pop();
                if(cost > dist[curr]) continue;
                for(auto [curr_node, curr_cost] : adj[curr]) {
                    if(!online[curr_node]) continue;
                    if(curr_cost < mid) continue;
                    if(dist[curr_node] > cost + curr_cost) {
                        dist[curr_node] = cost + curr_cost;
                        pq.push({dist[curr_node], curr_node});
                    }
                }
            }
            if(dist[n-1] != 1e9 && dist[n - 1] <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};