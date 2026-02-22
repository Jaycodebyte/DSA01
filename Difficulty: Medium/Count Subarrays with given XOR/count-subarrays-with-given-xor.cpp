class Solution {
  public:
  //Jay
     long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, long> freq;
        long count = 0;
        int prefixXor = 0;
        
        freq[0] = 1;
        
        for(int num : arr) {
            prefixXor ^= num;
            
            if(freq.find(prefixXor ^ k) != freq.end()) {
                count += freq[prefixXor ^ k];
            }
            
            freq[prefixXor]++;
        }
        
        return count;
    }
};