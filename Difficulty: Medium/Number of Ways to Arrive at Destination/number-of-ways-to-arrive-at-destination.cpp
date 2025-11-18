class Solution {
  public:
  // Jay
   int countPaths(int V, vector<vector<int>>& edges) {
        const long long MOD = 1000000007;
        
        vector<vector<pair<int, long long>>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        
        vector<long long> dist(V, LLONG_MAX);
        vector<long long> ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            
            for (auto& [v, w] : adj[u]) {
                long long newDist = d + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.emplace(newDist, v);
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[V - 1];
    }
};