class Solution {
  public:
   bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int count = 0;
        for(int i=0;i<arr.size();i++) if(arr[i]>=start && arr[i]<=end)count++;
        return count==(end-start+1);
    }
};
