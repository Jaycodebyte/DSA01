class Solution {
  public:
  //Jay
    int longestCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj(V, -1);
        for(auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        int ans = -1;
        
        for(int i = 0; i < V; i++) {
            if(visited[i]) continue;
            
            unordered_map<int, int> mp;
            int node = i;
            int step = 0;
            
            while(node != -1 && !visited[node]) {
                visited[node] = 1;
                mp[node] = step++;
                
                node = adj[node];
                
                if(node != -1 && mp.find(node) != mp.end()) {
                    ans = max(ans, step - mp[node]);
                    break;
                }
            }
        }
        
        return ans;
    }
};
