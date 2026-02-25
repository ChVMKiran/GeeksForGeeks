class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int curr = 0, n = arr.size(), ans = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            if(arr[i] > k) curr++;
            else curr--;
            if(curr > 0) ans = max(ans, i + 1);
            else if(ump.count(curr - 1)) {
                ans = max(ans, i - ump[curr - 1]);
            }
            if(!ump.count(curr)) ump[curr] = i;
        }
        return ans;
    }
};