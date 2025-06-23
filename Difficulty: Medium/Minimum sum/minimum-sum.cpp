class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0;
        while (num1 != "" && num2 != "") {
            int a = num1.back() - '0';
            num1.pop_back();
            int b = num2.back() - '0';
            num2.pop_back();
            res.push_back((a + b + carry) % 10 + '0');
            carry = max(0, (a + b + carry) / 10);
        }
        if (num1 != "")
            // cout << carry << num1.back();
        if (num1 != "") {
            while (num1 != "") {
                if (!carry)
                    res.push_back(num1.back());
                else {
                    res.push_back((num1.back() - '0' + carry) % 10 + '0');
                    carry = (num1.back() + carry - '0') / 10;
                }
                num1.pop_back();
            }
        } else {
            while (num2 != "") {
                if (!carry)
                    res.push_back(num2.back());
                else {
                    res.push_back((num2.back() - '0' + carry) % 10 + '0');
                    carry = (num2.back() + carry - '0') / 10;
                }
                num2.pop_back();
            }
        }
        if (carry)
            res.push_back(carry + '0');
        int n = res.size();
        for (int i = 0; i < n / 2; i++)
            swap(res[i], res[n - i - 1]);
        return res;
    }
    string minSum(vector<int>& arr) {
        // code here
        string str1 , str2;
        bool flag = true;
        vector<int> freq(10);
        for (int i = 0; i < arr.size(); i++)
            freq[arr[i]]++;
        for (int i = 1; i < 10; i++) {
            while (freq[i]) {
                if (flag)
                    str1 += (i + '0');
                else
                    str2 += (i + '0');
                flag = !flag;
                freq[i]--;
            }
        }
        // cout<<str1<<' '<<str2<<' ';
        return addStrings(str1, str2);
    }
};