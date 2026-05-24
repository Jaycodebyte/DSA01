class Solution {
  public:
    int coin(vector<int> &arr) {
    int i = 0;
    int j = arr.size() - 1;
    
    while(i < j) {
        if(arr[i] >= arr[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    
    return arr[i];
    }
};