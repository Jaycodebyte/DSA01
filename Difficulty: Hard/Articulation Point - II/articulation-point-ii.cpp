class Solution {
  public:
  //Jay
   void dfs(int node, int parent, vector<vector<int>> &adj,
             vector<int> &tin, vector<int> &low,
             vector<int> &vis, vector<int> &mark, int &timer) {
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        
        for(auto &nbr : adj[node]) {
            if(nbr == parent) continue;
            
            if(!vis[nbr]) {
                dfs(nbr, node, adj, tin, low, vis, mark, timer);
                
                low[node] = min(low[node], low[nbr]);
      
                if(low[nbr] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                
                child++;
            }
            else {
                low[node] = min(low[node], tin[nbr]);
            }
        }

        if(parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        // Build graph
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> tin(V, -1), low(V, -1);
        vector<int> vis(V, 0), mark(V, 0);
        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, tin, low, vis, mark, timer);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.empty()) return {-1};
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};