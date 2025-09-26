class Solution {
  public:
    //Jay
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;

        k %= n; 
        if (k == 0) return;

        if (type == 1) {
            rotate(dq.begin(), dq.end() - k, dq.end());
        } 
        else if (type == 2) {
            rotate(dq.begin(), dq.begin() + k, dq.end());
        }
    }
};