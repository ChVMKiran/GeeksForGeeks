class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), ans = 0;
        vector<int> invert(n + 1);
        for(int i = 0; i < n; i++) {
            if(i) {
                invert[i] ^= invert[i - 1];
            }
            arr[i] ^= invert[i];
            if(!arr[i]) {
                if(i > n - k) return -1;
                invert[i] ^= 1;
                invert[i + k] ^= 1;
                ans++;
            }
        }
        return ans;
    }
};