class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<int> st;
        int n = arr.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() > arr[i]) st.pop();
            st.push(arr[i]);
            ans += st.size();
        }
        return ans;
    }
};