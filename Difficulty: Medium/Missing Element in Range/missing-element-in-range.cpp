class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<int> ans;
        unordered_map<int, int> ump;
        for(auto& e: arr) {
            ump[e]++;
        }
        for(int i = low; i <= high; i++) {
            if(ump.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};