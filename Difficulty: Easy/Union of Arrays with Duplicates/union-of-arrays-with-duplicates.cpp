class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>ust(a.begin(), a.end());
        ust.insert(b.begin(), b.end());
        return vector<int>(ust.begin(), ust.end());
    }
};