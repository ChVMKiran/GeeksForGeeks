class Solution {
  public:
    bool isPos(vector<int>& arr, int x, int k) {
        int cnt = 1, curr = 0;
        for(int& e: arr) {
            curr += e;
            if(curr > x) {
                curr = e;
                cnt++;
                if(cnt > k) break;
            }
        }
        return cnt <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int maxi = arr[0], total = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            total += arr[i];
        }
        int low = maxi, high = total;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPos(arr, mid, k)) high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }
};