class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int ans = 0, n = arr.size(), sum = 0;
        stack<int> st;
        vector<int> left(n), right(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) right[i] = n - i;
            else right[i] = st.top() - i;
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) left[i] = i + 1;
            else left[i] = i - st.top();
            st.push(i);
            ans += right[i] * left[i] * arr[i];
        }
        return ans;
    }
};