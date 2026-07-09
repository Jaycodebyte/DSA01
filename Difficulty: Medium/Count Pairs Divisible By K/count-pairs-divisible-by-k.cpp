class Solution {
  public:
  //Jay
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<int>a(k , 0);
        int ans = 0;
        for(auto i :arr){
            i = i%k;
            if(i)ans+= a[k-i];
            else ans+= a[0];
            a[i]++;
        }
        return ans;
    }
};