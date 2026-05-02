class Solution {
  public:
  //Jay
   int findPosition(int n) {
        int cnt = 0, id = -1;
        
        for (int i = 0; i <= 31; i++) {
     
            int bit = (n >> i) & 1;
 
            if (bit == 1) cnt++;
  
            if (cnt > 1) break;

            if (cnt == 1 && id == -1) id = i + 1;
        }
        
        return (cnt > 1) ? -1 : id;
    }
};