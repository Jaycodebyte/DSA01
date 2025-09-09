class Solution {
  public:
           //Jay
     int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n = mices.size();
        int maxTime = 0;
        
        for (int i = 0; i < n; i++) {
            int time = abs(mices[i] - holes[i]);
            maxTime = max(maxTime, time);
        }
        return maxTime;
    }
};