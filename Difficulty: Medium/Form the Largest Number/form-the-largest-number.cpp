// User function template for C++
class Solution {
public:
    static bool comp(const string& a, const string& b) { 
        return a + b > b + a; 
    }
    string findLargest(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<string> strs;
        for (int i = 0; i < n; i++) {
            strs.push_back(to_string(arr[i]));
        }
        sort(strs.begin(), strs.end(), comp);
        if (strs[0] == "0")
            return "0";
        string res;
        for (int i = 0; i < n; i++)
            res += strs[i];
        return res;
    }
};
