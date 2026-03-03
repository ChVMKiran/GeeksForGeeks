class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size(), ans = 0;
        unordered_map<int, int> ump;
        for(int i = 0, j = 0; i < n; i++) {
            ump[arr[i]]++;
            while(ump.size() > 2) {
                if(--ump[arr[j]] == 0) ump.erase(arr[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};