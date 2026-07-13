class Solution {
  public:
  //Jay
    int minOperations(vector<int> &b) {
        const int MOD = 1000000007;
        int n = b.size();

        vector<int> vis(n, 0);

        unordered_map<int, int> mxExp;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int cur = i;
            int len = 0;

            while (!vis[cur]) {
                vis[cur] = 1;
                cur = b[cur] - 1;
                len++;
            }

            int x = len;
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    mxExp[p] = max(mxExp[p], cnt);
                }
            }

            if (x > 1)
                mxExp[x] = max(mxExp[x], 1);
        }

        long long ans = 1;

        for (auto &it : mxExp) {
            long long base = it.first;
            int exp = it.second;

            while (exp--) {
                ans = (ans * base) % MOD;
            }
        }

        return (int)ans;
    }
};