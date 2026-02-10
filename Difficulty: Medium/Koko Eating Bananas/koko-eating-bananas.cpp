class Solution {
  public:
    bool canEat(vector<int>& arr, int k, int x) {
        int cnt = 0;
        for(int& e: arr) {
            cnt += ceil((e * 1.0) / x);
            if(cnt > k) return false;
        }
        return cnt <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size(), l = 1, h = *max_element(arr.begin(), arr.end());
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(canEat(arr, k, m)) h = m - 1;
            else l = m + 1;
        }
        return l;
    }
};