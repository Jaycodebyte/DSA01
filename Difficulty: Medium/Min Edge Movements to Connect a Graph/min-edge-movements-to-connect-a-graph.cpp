class Solution {
  public:
   int findParent(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node],parent);
        
    }
    
    void join(int u,int v,vector<int>&parent,vector<int>&rank){
        
        int p1 = findParent(u,parent);
        int p2 = findParent(v,parent);
        
        if(p1==p2)return;
        else if(rank[p1]==rank[p2]){
            parent[p2] = p1;
            rank[p1]++;
        }
        else if(rank[p1]>rank[p2])parent[p2] = p1;
        else parent[p1] = p2;
        
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        int extra = 0;
        int group = 0;
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<m;i++){
            
            int p1 = findParent(edges[i][0],parent);
            int p2 = findParent(edges[i][1],parent);
            
            if(p1==p2)extra++;
            else join(edges[i][0],edges[i][1],parent,rank);
            
        }
        
        for(int i=0;i<n;i++){
            if(parent[i]==i)group++;
        }
        
        int need = group-1;
        
        if(need>extra)return -1;
        return need;
    }
};