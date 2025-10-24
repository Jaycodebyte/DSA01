class Solution {
  public:
    //Jay
     bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, need;
        for (int x : arr) freq[x]++;
        
        for (int x : arr) {
            if (freq[x] == 0) continue;
            freq[x]--;
            
            if (need[x] > 0) {
                need[x]--;
                need[x + 1]++;
            } 
            else {
                bool canStart = true;
                for (int i = 1; i < k; i++) {
                    if (freq[x + i] == 0) {
                        canStart = false;
                        break;
                    }
                }
                if (!canStart) return false;
                
                 // Use the next (k-1) consecutive numbers
                for (int i = 1; i < k; i++) freq[x + i]--;
                need[x + k]++;
            }
        }
        return true;
    }
};
