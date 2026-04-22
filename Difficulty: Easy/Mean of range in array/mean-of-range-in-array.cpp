class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> pre(n + 1);
        vector<int> ans;
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        for(auto& q: queries) {
            ans.push_back(pre[q[1] + 1] - pre[q[0]]);
            ans.back() /= (q[1] - q[0] + 1);
        }
        return ans;
    }
};