class Solution {
  public:
    int maxIndexDifference(string &s) {
        vector<int> best(26, -1);

        int ans = -1;

        for (int i = (int)s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            int reach;

            if (c == 25) {
                reach = i;
            }
            else if (best[c + 1] != -1) {
                reach = best[c + 1];
            }
            else {
                reach = i;
            }

            best[c] = max(best[c], reach);

            if (c == 0) {
                ans = max(ans, reach - i);
            }
        }

        return ans;
    }
};
