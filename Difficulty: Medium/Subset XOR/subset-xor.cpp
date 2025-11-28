class Solution {
  public:
   //Jay
     vector<int> subsetXOR(int n) {
        int X = 0;
        for(int i = 1; i <= n; i++)
            X ^= i;

        if (X == n) {
            vector<int> ans(n);
            for (int i = 1; i <= n; i++) ans[i-1] = i;
            return ans;
        }

        int k = X ^ n;
        if (k >= 1 && k <= n) {
            vector<int> ans;
            for (int i = 1; i <= n; i++)
                if (i != k) ans.push_back(i);
            return ans;
        }

        vector<int> ans(n-2);
        for(int i = 1; i <= n-2; i++)
            ans[i-1] = i;
        return ans;
        
    }
};
