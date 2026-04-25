class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            ans.push_back(arr[i]);
            while(ans.size() > 1 && (ans.back() < 0) != (ans[ans.size() - 2] < 0)) {
                int a = abs(ans.back()), b = abs(ans[ans.size() - 2]);
                if(a == b) {
                    ans.pop_back();
                    ans.pop_back();
                }
                else if(a < b) {
                    ans.pop_back();
                }
                else {
                    ans[ans.size() - 2] = ans.back();
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};