// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i = 0, j = 0, n = arr.size();
        for(i = 0; i < n; i++) {
            if(arr[i]) arr[j++] = arr[i];
        }
        for(i = j; i < n; i++) arr[i] = 0;
    }
};

