class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size(), ans = 0;
        unordered_map<char, int> ump;
        for(int i = 0, j = 0; i < n; i++) {
            ump[s[i]]++;
            while(ump.size() > k) {
                if(--ump[s[j]] == 0) ump.erase(s[j]);
                j++;
            }
            if(ump.size() == k) ans = max(ans, i - j + 1);
        }
        return ans == 0 ? -1 : ans;
    }
};