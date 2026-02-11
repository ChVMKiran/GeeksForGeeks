class Solution {
  public:
    int calCost(vector<int>& heights, vector<int>& cost, int x) {
        int n = heights.size(), res = 0;
        for(int i = 0; i < n; i++) {
            res += cost[i] * abs(heights[i] - x);
        }
        return res;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size(), ans = INT_MAX, low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cost1 = calCost(heights, cost, mid - 1), cost2 = calCost(heights, cost, mid);
            int cost3 = calCost(heights, cost, mid + 1);
            if(cost1 >= cost2 && cost2 <= cost3) return cost2;
            else if(cost1 >= cost2 && cost2 >= cost3) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
