class Solution {
  public:
    int ans = -1;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int curr) {
        if(vis[node] != -1) {
            ans = max(ans, curr - vis[node]);
            return;
        }
        vis[node] = curr;
        for(int &nn: adj[node]) {
            dfs(adj, vis, nn, curr + 1);
        }
        vis[node] = -1;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, -1);
        vector<vector<int>> adj(V);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < V; i++) {
            if(vis[i] == -1) dfs(adj, vis, i, 0);
        }
        return ans;
    }
};
