class Solution {
  public:
  //Jay
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return 0;
        int buy = -arr[0];
        int sell = 0;  
        for(int i = 1; i < n; i++) {
            int newBuy = max(buy, sell - arr[i]);
            int newSell = max(sell, buy + arr[i] - k);
            
            buy = newBuy;
            sell = newSell;
        }
        return sell;
    }
};