class Solution {
  public:
   //Jay
   int minCost(vector<int>& arr) {
       //code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int x : arr) pq.push(x);
        int totalCost = 0;
        
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            int cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        
        return totalCost;
    }
};