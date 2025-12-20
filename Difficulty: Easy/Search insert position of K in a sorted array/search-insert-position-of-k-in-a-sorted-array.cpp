class Solution {
  public:
  //Jay
   int searchInsertK(vector<int> &arr, int k) {
    int n = arr.size(); 
    if(k <= arr[0]) return 0;
    if(k > arr[n-1]) return n;
    
    int l = 0, r = n-1;
    while(l < r) {
        int m =  l + (r - l + 1)/2;
        if(arr[m] < k)
            l = m;
        else
            r = m - 1;
    }
    return l+1;
        
    }
};