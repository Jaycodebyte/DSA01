class Solution {
  public:
  //Jay
   vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if(V == 1) return {0};
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);
        // Build graph
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(degree[i] == 1)
                q.push(i);
        }
        int remaining = V;
        while(remaining > 2) {
            int size = q.size();
            remaining -= size;
            
            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                
                for(auto &nbr : adj[node]) {
                    degree[nbr]--;
                    
                    if(degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        vector<int> ans;
        
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};