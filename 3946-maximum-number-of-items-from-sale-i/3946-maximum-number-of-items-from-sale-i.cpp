class Solution {
public:
    int f(int idx, int budget, int& mini ,vector<vector<int>>& items, vector<vector<int>>& dp, unordered_map<int, int>& mp) {
        if(idx >= items.size() || budget <= 0) return budget / mini;
        if(dp[idx][budget] != -1) return dp[idx][budget];
        int take = 0;
        int skip = f(idx+1, budget, mini, items, dp, mp);
        if(budget >= items[idx][1]) {
            take = 1 + mp[idx] + f(idx + 1, budget - items[idx][1], mini, items, dp, mp);
        }
        return dp[idx][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int f1 = items[i][0], f2 = items[j][0];
                if(f2 % f1 == 0) {
                    mp[i]++;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));
        return f(0, budget, mini, items, dp, mp);
    }
};