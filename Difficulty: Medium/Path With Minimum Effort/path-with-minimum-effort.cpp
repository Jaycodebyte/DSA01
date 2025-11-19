class Solution {
  public:
   //Jay
       int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        pq.push({0, 0, 0}); 

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int effort = top[0];
            int x = top[1];
            int y = top[2];

            if (x == n - 1 && y == m - 1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int diff = abs(mat[x][y] - mat[nx][ny]);
                    int newEffort = max(effort, diff);

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
