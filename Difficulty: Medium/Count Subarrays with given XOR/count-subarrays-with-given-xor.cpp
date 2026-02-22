class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long pre=0, ans=0;
        unordered_map<int, int> ump;
        ump[0]++;
        for(int &i: arr) {
            pre ^= i;
            if(ump.count(pre ^ k)) {
                ans += ump[pre ^ k];
            }
            ump[pre]++;
        }
        return ans;
    }
};
