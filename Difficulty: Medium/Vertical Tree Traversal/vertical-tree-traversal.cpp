/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        int mini = 0, maxi = 0;
        unordered_map<int, vector<int>> ump;
        queue<pair<Node*, int>> qu;
        qu.push({root, 0});
        while(!qu.empty()) {
            auto &[node, dist] = qu.front();
            ump[dist].push_back(node->data);
            mini = min(mini, dist);
            maxi = max(maxi, dist);
            if(node->left) qu.push({node->left, dist - 1});
            if(node->right) qu.push({node->right, dist + 1});
            qu.pop();
        }
        vector<vector<int>> ans(ump.size());
        for(int i = mini; i <= maxi; i++) {
            ans[i - mini] = ump[i];
        }
        return ans;
    }
};