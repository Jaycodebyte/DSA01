class Solution {
  public:
    int cntOnes(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int newr = r + dx[k];
                int newc = c + dy[k];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m &&
                   grid[newr][newc] == 1 && visited[newr][newc] == 0) {
                    visited[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};