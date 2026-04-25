class Solution {
  public:
  //Jay
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;

        for (int x : arr) {
            bool destroyed = false;

            while (!st.empty() && st.back() * x < 0) {
                if (abs(st.back()) < abs(x)) {
                    st.pop_back();
                }
                else if (abs(st.back()) == abs(x)) {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(x);
            }
        }

        return st;
    }
};