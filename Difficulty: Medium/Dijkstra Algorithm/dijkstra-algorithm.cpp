class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, INT_MAX);
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if(cost != dist[node]) continue;
            for(auto& [nn, c]: adj[node]) {
                if(dist[nn] > cost + c) {
                    dist[nn] = cost + c;
                    pq.push({cost + c, nn});
                }
            }
        }
        return dist;
    }
};