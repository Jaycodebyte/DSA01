class Solution {
  public:
  //Jay
     int minSteps(vector<int> &arr, int start, int end) {
    // Edge Case
    if(start == end) {
        return 0;
    }
    
    // Mod is 1000, so 1000 values at max
    vector<int> steps(1000, 1e9);
    queue<int> q;
    
    steps[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // Like recursion, multiplying with every element
        for(int &val: arr) {
            int next = (curr * val) % 1000;
            
            // Same as min step in recursion, step + 1 because the step is valid or not
            if(steps[curr] + 1 < steps[next]) {
                steps[next] = steps[curr] + 1;
                
                if(next == end) {
                    return steps[next];
                }
                
                q.push(next);
            }
        }
    }
    
    return -1;
    }
};