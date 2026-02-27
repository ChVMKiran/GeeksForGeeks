class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<vector<long long>> pre(m, vector<long long>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pre[i][j] += mat[i][j];
                if(i) pre[i][j] += pre[i - 1][j];
                if(j) pre[i][j] += pre[i][j - 1];
                if(i && j) pre[i][j] -= pre[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= min(m, n); i++) {
            for(int j = i - 1; j < m; j++) {
                for(int k = i - 1; k < n; k++) {
                    int curr = pre[j][k];
                    if(j > i - 1) curr -= pre[j - i][k];
                    if(k > i - 1) curr -= pre[j][k - i];
                    if(j > i - 1 && k > i - 1) curr += pre[j - i][k - i];
                    if(curr == x) ans++;
                }
            }
        }
        return ans;
    }
};