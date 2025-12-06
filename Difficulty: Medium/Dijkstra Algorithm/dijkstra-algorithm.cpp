class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            auto top = pq.top();
            int node = top.second, distance = top.first;
            pq.pop();
            if(distance > dist[node]) continue;
            for(auto n: adj[node]) {
                if(distance + n.second < dist[n.first]) {
                    dist[n.first] = distance + n.second;
                    pq.push({dist[n.first], n.first});
                }
            }
        }
        return dist;
    }
};