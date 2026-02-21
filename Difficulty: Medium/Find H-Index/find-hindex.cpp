// User function Template for C++
class Solution {
public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> freq(n + 1, 0);
        for (int& i : citations) {
            freq[min(i, n)]++;
        }

        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += freq[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};
