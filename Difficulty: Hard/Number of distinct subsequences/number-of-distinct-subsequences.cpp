class Solution {
  public:
  //Jay
    int distinctSubseq(string &str) {
        const int MOD = 1e9 + 7;
        int n = str.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 

        vector<int> last(26, -1);

        for(int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            int c = str[i - 1] - 'a';

            if(last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }

            last[c] = i;
        }

        return dp[n];
    }
};