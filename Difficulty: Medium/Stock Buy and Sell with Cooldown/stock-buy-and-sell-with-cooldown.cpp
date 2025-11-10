class Solution {
  public:
    //Jay
     int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int hold = -arr[0], sold = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int new_hold = max(hold, cooldown - arr[i]);
            int new_sold = hold + arr[i];
            int new_cooldown = max(cooldown, sold);
            hold = new_hold;
            sold = new_sold;
            cooldown = new_cooldown;
        }
        return max(sold, cooldown);
    }
};