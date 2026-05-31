class Solution {
  public:
  //Jay
    bool isSumOfConsecutive(int n) {
        // code here
    while(n>1){
        if(n &1)return 1;
        n= n>>1;
    }
    return false;
    }
    
    // return (n &(n-1)) != 0;
    

    
};