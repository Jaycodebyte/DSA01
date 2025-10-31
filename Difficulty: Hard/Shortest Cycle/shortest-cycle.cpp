class Solution {
  public:
   //Jay
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;
        
        for (int i = 0; i < V; i++) {
            vector<int> dist(V, -1), parent(V, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                
                for (int nei : adj[node]) {

                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        parent[nei] = node;
                        q.push(nei);
                    }
                   
                    else if (parent[node] != nei) {
                        ans = min(ans, dist[node] + dist[nei] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans; // If no cycle found
    }
};
