class Solution {
  public:
  //Jay
int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();

        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int result = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAchieve(arr, k, w, mid)) {
                result = mid;
                low = mid + 1;   // try higher
            } else {
                high = mid - 1;  // try lower
            }
        }

        return result;
    }

private:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<long long> water(n + 1, 0);  // difference array
        long long ops = 0, currWater = 0;

        for (int i = 0; i < n; i++) {
            currWater += water[i];
            long long height = arr[i] + currWater;

            if (height < target) {
                long long need = target - height;
                ops += need;

                if (ops > k)
                    return false;

                currWater += need;

                if (i + w < n)
                    water[i + w] -= need;
            }
        }

        return true;
    }
};