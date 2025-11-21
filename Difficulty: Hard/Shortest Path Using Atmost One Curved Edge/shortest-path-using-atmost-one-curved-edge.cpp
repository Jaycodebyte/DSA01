class Solution {
  public:
  //Jay
       const long long INF = 1e18;

    vector<long long> dijkstra(int V, int src, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(V, INF);
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d != dist[node]) continue;

            for (auto &it : adj[node]) {
                int nxt = it.first;
                long long wt = it.second;
                if (dist[nxt] > dist[node] + wt) {
                    dist[nxt] = dist[node] + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return dist;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int x = e[0], y = e[1];
            int w1 = e[2];
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        vector<long long> distA = dijkstra(V, a, adj);
        vector<long long> distB = dijkstra(V, b, adj);

        long long ans = distA[b];

        for (auto &e : edges) {
            int x = e[0], y = e[1];
            int w2 = e[3];

            if (distA[x] < INF && distB[y] < INF)
                ans = min(ans, distA[x] + w2 + distB[y]);

            if (distA[y] < INF && distB[x] < INF)
                ans = min(ans, distA[y] + w2 + distB[x]);
        }

        if (ans >= INF) return -1;
        return (int)ans;
    }
};