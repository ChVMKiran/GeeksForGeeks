class Solution {
  public:
    void buildLPS(vector<int>& pat, vector<int>& lps) {
        int len = 0, i = 1;
        while(i < pat.size()) {
            if(pat[i] == pat[len]) {
                lps[i++] = ++len;
            }
            else {
                if(len > 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size(), m = b.size();
        vector<int> lps(m);
        vector<int> ans;
        buildLPS(b, lps);
        int i = 0, j = 0;
        while(i < n) {
            if(a[i] == b[j]) {
                i++;
                j++;
                if(j == m) {
                    ans.push_back(i - m);
                    j = lps[j - 1];
                }
            }
            else {
                if(j > 0) j = lps[j - 1];
                else i++;
            }
        }
        return ans;
    }
};