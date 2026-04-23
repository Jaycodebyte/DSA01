class Solution {
  public:
  //Jay
  bool canSplit(vector<int>& arr) {
        long long total = 0;
        
        for(int num : arr) {
            total += num;
        }
        
        if(total % 2 != 0) return false;
        
        long long target = total / 2;
        long long prefixSum = 0;
        
        for(int i = 0; i < arr.size() - 1; i++) {
            prefixSum += arr[i];
            if(prefixSum == target) return true;
        }
        
        return false;
        
    }
};
