class Solution {
  public:
    int sum(int n) {
        int s = 0;
        while(n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int getCount(int n, int d) {
        // code here
        int l = 1, h = n;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(m - sum(m) >= d) {
                h = m - 1;
            }
            else l = m + 1;
        }
        return n - h;
    }
};