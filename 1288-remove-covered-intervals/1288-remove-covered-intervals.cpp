class Solution {
public:
bool f(int a, int b, int c, int d) {
    if(c <= a && b <= d) return true;
    return false;
}
    int removeCoveredIntervals(vector<vector<int>>& it) {
        int n = it.size();
        cout << n << endl;
        int ans = n;
        for(int i = 0; i < n; i++) {
            int a = it[i][0], b = it[i][1];

            cout << i << " " << a << " " << b << "--" << endl;

            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int c = it[j][0], d = it[j][1];

                cout << c << " " << d << endl;

                bool can = f(a, b, c, d);
                if(can) {

                    cout << "done" << endl;

                    ans--;
                    break;
                }
            }

            // cout << "--" << endl;
        }
        return ans;
    }
};