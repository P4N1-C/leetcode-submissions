class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int one = 0, zero = 0;
        for(char c : s) {
            if(c == '0') zero++;
            else one++;
        }
        vector<bool> ans;
        for(string& curr : strs) {
            int currZero = 0, currOne = 0;
            for(char c : curr) {
                if(c == '0') currZero++;
                else if (c =='1') currOne++;
            }
            if(currZero  > zero || currOne > one) {
                ans.push_back(false);
                continue;
            }
            int need = zero - currZero;
            int have = 0;
            bool ok = true;
            for(int i = 0; i < n; i++) {
                if(s[i] == curr[i]) continue;
                if(s[i] != curr[i] && curr[i] == '?') {
                    if(need > 0) {
                        if (s[i] == '1') have++; 
                        need--;
                    } else {
                        if (s[i] == '0') {
                            if (have <= 0) { ok = false; break; }
                            have--;
                        }
                    }
                    continue;
                }
                if(s[i] != curr[i]) {
                    if(s[i] == '0') {
                        if(have <= 0) {
                            ok = false; 
                            break;
                        }
                        have--;
                    } 
                    else if(s[i] == '1') {
                        have++;
                    }
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};