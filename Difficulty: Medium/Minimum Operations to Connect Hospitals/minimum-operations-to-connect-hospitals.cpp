class Solution {
  public:
   //Jay
     vector<int> parent, rankv;

     int findp(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findp(parent[x]);
       }

    void unite(int x, int y) {
        x = findp(x);
        y = findp(y);
        if (x == y) return;
        if (rankv[x] < rankv[y]) parent[x] = y;
        else if (rankv[y] < rankv[x]) parent[y] = x;
        else parent[y] = x, rankv[x]++;
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rankv.assign(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        int redundant = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (findp(u) == findp(v))
                redundant++;
            else
                unite(u, v);
        }

        int components = 0;
        for (int i = 0; i < V; i++)
            if (findp(i) == i) components++;

        int needed = components - 1;

        if (redundant >= needed) return needed;
        return -1;
    }
};
