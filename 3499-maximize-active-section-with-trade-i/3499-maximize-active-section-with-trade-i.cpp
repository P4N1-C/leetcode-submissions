class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int oo = 0;
        for(char c : s) oo += (c - '0'); 
        int ans = oo;
        for(int i = 0; i < n; i++) {
            if (s[i] == '1' || (i > 0 && s[i - 1] == '0')) continue;
            int curr = 0;
            bool d = false;
            bool done = false;
            int k = i; 
            while(k < n && s[k] == '0') {
                int j = k + 1;
                if(j < n && s[j] == '1') {
                    if(d == false) {
                        d = true;
                        while(j < n && s[j] == '1') {
                            j++;
                        }
                    }
                }
                curr++;
                if (d && j == k + 1) {
                    done = true;
                }
                k = j; 
                if (done) {
                    ans = max(ans, curr + oo); 
                }
            }
        }
        return ans;
    }
};