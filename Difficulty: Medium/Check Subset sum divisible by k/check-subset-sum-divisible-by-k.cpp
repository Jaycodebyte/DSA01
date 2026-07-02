class Solution {
public:
//Jay
    bool divisibleByK(vector<int> &arr, int &k) {

        vector<bool> dp(k, false);

        for (int x : arr) {

            vector<bool> ndp(dp);

            // Start a new subset
            ndp[x % k] = true;

            // Extend existing subsets
            for (int rem = 0; rem < k; rem++) {
                if (dp[rem]) {
                    ndp[(rem + x) % k] = true;
                }
            }

            dp = ndp;

            if (dp[0]) return true;
        }

        return false;
    }
};