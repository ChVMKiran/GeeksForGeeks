/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        Node *temp;
        queue<pair<Node *, int>> q;
        unordered_map<int, int> ump;
        int mini = INT_MAX;
        q.push({root, 0});
        while (!q.empty()) {
            temp = q.front().first;
            int d = q.front().second;
            mini = min(mini, d);
            q.pop();
            if (ump.find(d) == ump.end()) {
                ump[d] = temp->data;
            }
            if (temp->left) {
                q.push({temp->left, d - 1});
            }
            if (temp->right) {
                q.push({temp->right, d + 1});
            }
        }
        vector<int> ans(ump.size());
        for (auto it = ump.begin(); it != ump.end(); it++) {
            ans[it->first - mini] = (it->second);
        }
      
        return ans;
    }
};