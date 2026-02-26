class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        vector<char> a(26, '-'), b(26, '-');
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            int u = s1[i] - 'a', v = s2[i] - 'a';
            if(a[u] != '-') {
                if(a[u] != 'a' + v) return false;
            }
            if(b[v] != '-') {
                if(b[v] != 'a' + u) return false;
            }
            a[u] = v + 'a';
            b[v] = u + 'a';
        }
        return true;
    }
};