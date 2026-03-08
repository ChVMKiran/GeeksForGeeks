class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size(), maxi = *max_element(arr.begin(), arr.end());
        vector<bool> frq(maxi + 1);
        for(int i = 0; i < n; i++) {
            frq[arr[i]] = true;
        }
        for(int a = 1; a <= maxi; a++) {
            if(!frq[a]) continue;
            for(int b = 1; b <= maxi; b++) {
                if(!frq[b]) continue;
                int c = sqrt(a * a + b * b);
                if(c * c != a * a + b * b || c > maxi || !frq[c]) continue;
                return true;
            }
        }
        return false;
    }
};