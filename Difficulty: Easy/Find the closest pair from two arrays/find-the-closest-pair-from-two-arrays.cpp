class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int m = arr1.size(), n = arr2.size(), mini = INT_MAX, i = 0, j = n - 1;
        vector<int> ans(2);
        while(i < m && j >= 0) {
            int curr = arr1[i] + arr2[j];
            if(abs(curr - x) < mini) {
                mini = abs(curr - x);
                ans[0] = arr1[i];
                ans[1] = arr2[j];
            }
            if(curr > x) j--;
            else i++;
        }
        return ans;
    }
};