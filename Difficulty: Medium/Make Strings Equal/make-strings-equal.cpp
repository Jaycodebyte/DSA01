class Solution {
  public:
    //Jay
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> dist(26, vector<int>(26, INF));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd Warshall for all pairs min cost
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long answer = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == t[i]) continue;

            int a = s[i] - 'a';
            int b = t[i] - 'a';

            int best = INF;

            for (int k = 0; k < 26; k++) {
                if (dist[a][k] < INF && dist[b][k] < INF) {
                    best = min(best, dist[a][k] + dist[b][k]);
                }
            }

            if (best == INF) return -1;

            answer += best;
        }

        return answer;
    }
};