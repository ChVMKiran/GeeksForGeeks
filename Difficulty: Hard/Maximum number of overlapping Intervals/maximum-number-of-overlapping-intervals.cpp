class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        vector<int> starts(n), ends(n);
        for(int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
            ends[i] = arr[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ans = 0, cnt = 0, i = 0, j = 0;
        while(i < n && j < n) {
            if(starts[i] <= ends[j]) i++, cnt++;
            else j++, cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
