class Solution {
  public:
  
   //Jay
      int cntWays(vector<int>& arr) {
        int n = arr.size();
        int totalEven = 0, totalOdd = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {

            if(i % 2 == 0) totalEven -= arr[i];
            else totalOdd -= arr[i];

            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd + totalEven;

            if(newEven == newOdd) count++;

            if(i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }

        return count;
    }
};