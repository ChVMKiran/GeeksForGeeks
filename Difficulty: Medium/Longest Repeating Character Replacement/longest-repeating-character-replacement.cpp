class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size(), ans = 0, maxFreq = 0;
        unordered_map<char, int> ump;
        for(int l = 0, r = 0; r < n; r++) {
            ump[s[r]]++;
            maxFreq = max(maxFreq, ump[s[r]]);
            if(r - l + 1 - maxFreq > k) {
                ump[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// yes, even i thought the same but actually it don't need to be updated because the result size would be recorded correctly and any other substring. The key point here is the substring we are considering can be invalid but there definitely exists some valid substring with size of this substing, how?
// because we recorded the size when it is valid and any other invalid substrings afterwards can't become larger than this.
// work on example s = "AAABCD"
// when we reach 'D', our current substring is AABCD which is invalid but AAABC is valid, recorded and of same size. So this won't cause issue here.