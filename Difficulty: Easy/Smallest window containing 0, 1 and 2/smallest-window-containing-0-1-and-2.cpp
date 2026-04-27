class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int ans = -1, zero = -1, one = -1, two = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') zero = i;
            else if(s[i] == '1') one = i;
            else two = i;
            if(zero != -1 && one != -1 && two != -1) {
                if(ans == -1) ans = i - min({zero, one, two}) + 1;
                else ans = min(ans, i - min({zero, one, two}) + 1);
            }
        }
        return ans;
    }
};
