class Solution {
  public:
    bool isSafe(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        queue<pair<int, int>> qu;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 2) qu.push({i, j});
            }
        }
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}, ans = 0;
        while(!qu.empty()) {
            int sz = qu.size();
            bool flag = false;
            while(sz--) {
                auto [x, y] = qu.front();
                qu.pop();
                for(int i = 0; i < 4; i++) {
                    if(isSafe(x + dir[i][0], y + dir[i][1], m, n) && mat[x + dir[i][0]][y + dir[i][1]] == 1) {
                        flag = true;
                        qu.push({x + dir[i][0], y + dir[i][1]});
                        mat[x + dir[i][0]][y + dir[i][1]] = 2;
                    }
                }
            }
            if(!flag) break;
            ans++;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};