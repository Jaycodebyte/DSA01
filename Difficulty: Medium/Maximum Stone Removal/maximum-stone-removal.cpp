class Solution {
  public:
  //Jay
    unordered_map<int, int> parent, rankv;

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

    int maxRemove(vector<vector<int>>& stones) {
        parent.clear();
        rankv.clear();
        
        int offset = 10001;

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + offset;
            if (!parent.count(row)) parent[row] = row;
            if (!parent.count(col)) parent[col] = col;
            if (!rankv.count(row)) rankv[row] = 0;
            if (!rankv.count(col)) rankv[col] = 0;
        }
        
        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + offset;
            unite(row, col);
        }

        unordered_set<int> components;
        for (auto &s : stones) {
            int row = s[0];
            components.insert(findp(row));
        }
        return stones.size() - components.size();
    }
};