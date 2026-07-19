class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }
        stack<char> st;
        vector<int> used(26, 0);
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(used[c - 'a']) continue;
            while(!st.empty()) {
                char curr = st.top();
                if(curr > c && mp[curr] > i) {
                    st.pop();
                    used[curr - 'a'] = 0;
                } else {
                    break;
                }
            }
            st.push(c);
            used[c - 'a'] = 1;
        }
        string ans = "";
        while(!st.empty()) {
            char c = st.top(); st.pop();
            ans = c + ans;
        }
        return ans;
    }
};