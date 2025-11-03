class Solution {
  public:
     //Jay
       bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, safe)) return true;
            } 
            else if (pathVis[it]) return true;
        }
        
        safe[node] = 1; // node is safe if no cycle detected in path
        pathVis[node] = 0;
        return false;
    }

     vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);
        
        vector<int> vis(V, 0), pathVis(V, 0), safe(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, adj, vis, pathVis, safe);
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) ans.push_back(i);
        }
        
        return ans;
    }
};