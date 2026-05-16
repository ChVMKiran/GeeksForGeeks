class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(), arr.end());
        int ans = 1;
        for(int i:arr){
            if(i > ans) return ans;
            ans += i;
        }
        return ans;
    }
};