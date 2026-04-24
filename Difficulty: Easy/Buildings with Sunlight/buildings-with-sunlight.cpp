class Solution {
  public:
  //Jay
    int visibleBuildings(vector<int>& arr) {
        int maxHeight = INT_MIN;
        int count = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= maxHeight) {
                maxHeight = arr[i];
                count++;
            }
        }

        return count;
    }
};