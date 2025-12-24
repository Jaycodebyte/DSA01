class Solution {
    public:
    //Jay
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        auto lastIndex = [&](int l, int r) {
            int ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[mid] <= x) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return ans;
        };

        int count = 0;

        // Search left part
        int idx1 = lastIndex(0, pivot - 1);
        if (idx1 != -1) count += (idx1 + 1);

        // Search right part
        int idx2 = lastIndex(pivot, n - 1);
        if (idx2 != -1) count += (idx2 - pivot + 1);

        return count;
        
    }
};