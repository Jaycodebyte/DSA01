class Solution {
  public:
  //Jay
     string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            int j = 0, k = i;

            while (k < n && j < m) {
                if (s1[k] == s2[j]) j++;
                k++;
            }

            if (j == m) {
                int end = k - 1;
                j = m - 1;
                k = end;

                while (k >= i) {
                    if (s1[k] == s2[j]) j--;
                    if (j < 0) break;
                    k--;
                }

                int start = k;

                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    ans = s1.substr(start, minLen);
                }

                i = start;
            }
        }
        return ans;
    }
};
