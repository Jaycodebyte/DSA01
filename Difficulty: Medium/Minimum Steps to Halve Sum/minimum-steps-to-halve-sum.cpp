class Solution {
  public:
    //Jay
   int minOperations(vector<int>& arr) {
        priority_queue<double> pq;
        double total = 0;
        
        for (int x : arr) {
            pq.push(x);
            total += x;
        }
        // half the total
        double target = total / 2.0;
        double currSum = total;
        int steps = 0;
        
        while (currSum > target) {
            double top = pq.top();
            pq.pop();
            
            // half the top most greater element
            double half = top / 2.0;
            currSum -= (top - half);
            pq.push(half);
            steps++;
        }
        
        return steps;
    }
};