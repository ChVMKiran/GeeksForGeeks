class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), ans = 0, curr = 0;
        for(int i = 0; i < n; i++) {
            curr ^= arr[i];
            if(i < k - 1) continue;
            if(i >= k) curr ^= arr[i - k];
            ans = max(ans, curr);
        }
        return ans;
    }
};