/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  private:
    bool helper(Node* root1, Node* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return root1 -> data == root2 -> data && 
        helper(root1 -> left, root2 -> right) && 
        helper(root1 -> right, root2 -> left);
    }
    
  public:
    bool isSymmetric(Node* root) {
        // Code here
        return helper(root -> left, root -> right);
    }
};