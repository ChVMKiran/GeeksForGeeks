/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int fun(Node* root, int k, int curr, unordered_map<int, int>& ump) {
        if(!root) return 0;
        curr += root->data;
        int res = 0;
        if(ump.count(curr - k)) res += ump[curr - k];
        ump[curr]++;
        res += fun(root->left, k, curr, ump);
        res += fun(root->right, k, curr, ump);
        ump[curr]--;
        return res;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int, int> ump;
        ump[0] = 1;
        return fun(root, k, 0, ump);
    }
};