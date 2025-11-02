class Solution {
  public:
     int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        
        // Total possible edges in a DAG = V*(V-1)/2 
        // this is the formula to be remember
        return (V * (V - 1)) / 2 - E;
    
    }
};
