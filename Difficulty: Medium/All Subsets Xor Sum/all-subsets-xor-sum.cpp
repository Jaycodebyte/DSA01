class Solution {
  public:
  //Jay 
     int subsetXORSum(vector<int>& arr) {
        int OR = 0, n = arr.size();
        for(int x : arr) OR |= x;
        return OR * (1 << (n - 1));
    }
};