// User function Template for C++

class Trie {
  public:
    int val;
    Trie* arr[2];
    Trie() {
        val = 0;
        arr[0] = arr[1] = nullptr;
    }
};

void insert(int n, Trie* root) {
    Trie* temp = root;
    for(int i = 31; i >=0 ; i--) {
        int b = (n >> i) & 1;
        if(b) {
            if(!temp->arr[1]) {
                temp->arr[1] = new Trie();
            }
            temp = temp->arr[1];
        }
        else {
            if(!temp->arr[0]) {
                temp->arr[0] = new Trie();
            }
            temp = temp->arr[0];
        }
    }
    temp->val = n;
}

int query(int pre, Trie* root) {
    Trie* temp = root;
    for(int i = 31; i >=0 ; i--) {
        int b = (pre >> i) & 1;
        if(temp->arr[!b]) {
            temp = temp->arr[!b];
        }
        else if(temp->arr[b]) {
            temp = temp->arr[b];
        }
    }
    return pre ^ (temp->val);
}

class Solution {
  public:
    int maxSubarrayXOR(int N, int arr[]) {
        // code here
        Trie* root = new Trie();
        insert(0, root);
        int ans = 0, pre = 0;
        for(int i = 0; i < N; i++) {
            pre ^= arr[i];
            insert(pre, root);
            ans = max(ans, query(pre, root));
        }
        return ans;
    }
};