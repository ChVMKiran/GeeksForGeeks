class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int curr = 0, n = a1.size(), ans = 0;
        unordered_map<int, int> ump;
        ump[0] = -1;
        for(int i = 0; i < n; i++) {
            if(a1[i] == 1) curr++;
            if(a2[i] == 1) curr--;
            if(ump.count(curr)) ans = max(ans, i - ump[curr]);
            else ump[curr] = i;
        }
        return ans;
    }
};