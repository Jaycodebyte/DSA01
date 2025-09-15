class Solution {
  public:
          //Jay
  bool stringStack(string &pat, string &tar) {
        int n = pat.size(), m = tar.size();
        if (m == 0) return true;
        int j = m - 1;
        int skip = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (skip > 0) {
                --skip;
            } else if (j >= 0 && pat[i] == tar[j]) {
                --j;
                if (j < 0) return true;
            } else {
                ++skip;
            }
        }
        return (j < 0);
    }
};