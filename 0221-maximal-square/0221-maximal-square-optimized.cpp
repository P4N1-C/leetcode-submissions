class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0)), up(m, vector<int>(n, 0)), arr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = matrix[i][j] - '0';
                if(curr == 0) continue;
                if (j - 1 >= 0) {
                    left[i][j] = 1 + left[i][j - 1];
                } else {
                    left[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curr = matrix[j][i] - '0';
                if(curr == 0) continue;
                if (j - 1 >= 0) {
                    up[j][i] = curr + up[j - 1][i];
                } else {
                    up[j][i] = curr;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = min(left[i][j], up[i][j]);
            }
        }
        for(auto it : arr) {
            for(auto i : it) {
                cout << i << " ";
            }
            cout << endl;
        }
        int size = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i + size >= m || j + size >= n) continue;
                int ii = i, jj = j;
                int curr = 0;
                int need = 1;
                while(ii < m && jj < n) {
                    if(arr[ii][jj] < need) break;
                    curr = need;
                    need++;
                    ii++;
                    jj++;
                }
                size = max(size, curr);
            }
        }
        return size*size;
    }
};