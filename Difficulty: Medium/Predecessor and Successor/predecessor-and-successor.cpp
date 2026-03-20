/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans(2, nullptr);
        Node* target = nullptr;
        while(root) {
            if(root->data > key) {
                ans[1] = root;
                root = root->left;
            }
            else if(root->data < key) {
                ans[0] = root;
                root = root->right;
            }
            else {
                target = root;
                break;
            }
        }
        if(target && target->left) {
            Node* pre = target->left;
            while(pre && pre->right) pre = pre->right;
            ans[0] = pre;
        }
        if(target && target->right) {
            Node* succ = target->right;
            while(succ && succ->left) succ = succ->left;
            ans[1] = succ;
        }
        return ans;
    }
};