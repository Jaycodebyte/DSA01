class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int left = 1, right = 0;

        // Find max pile
        for (int pile : arr)
            right = max(right, pile);

        // Set result (worst case)
        int res = right;

        // Binary search on eating speed
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(arr, k, mid)) {
                res = mid;        // possible, try smaller speed
                right = mid - 1;
            } else {
                left = mid + 1;  // too slow, try bigger speed
            }
        }

        return res;
    }

    bool canFinish(vector<int>& arr, int k, int s) {
        long long hours = 0;

        for (int pile : arr) {
            hours += (pile + s - 1) / s;  // ceil(pile / s)
            if (hours > k)
                return false;
        }

        return hours <= k;
    }
};