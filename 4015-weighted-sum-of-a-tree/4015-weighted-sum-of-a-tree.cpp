class Solution {
public:
    int f(int currNode, vector<vector<int>> & adj) {
        int maxi = 1;
        for(auto node : adj[currNode]) {
            maxi = max(maxi, 1 + f(node, adj));
        }
        return maxi;
    }
    long long ff(int currNode, vector<vector<int>>& adj, int h , vector<int>& nums, int d) {
        long long curr = 1LL * nums[currNode] * (h - d + 1);
        for(auto node : adj[currNode]) {
            curr += ff(node, adj, h, nums, d + 1);
        }   
        return curr;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        int h = f(0, adj);
        return ff(0, adj, h, nums, 1);
    }
};