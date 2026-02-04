class Solution {
  public:
  //Jay
   int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        for (int pos : left) {
            if (pos > ans) {
                ans = pos;
            }
        }

        int minRight = n;
        bool hasRight = false;

        for (int pos : right) {
            if (pos < minRight) {
                minRight = pos;
            }
            hasRight = true;
        }

        if (hasRight) {
            ans = max(ans, n - minRight);
        }

        return ans;
    }
};