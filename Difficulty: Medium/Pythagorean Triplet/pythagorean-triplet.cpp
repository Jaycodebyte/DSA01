class Solution {
  public:
  //Jay
      bool pythagoreanTriplet(vector<int>& arr) {
        
        vector<int> freq(1001,0);
        
        for(int x : arr)
            freq[x]++;
        
        for(int a = 1; a <= 1000; a++){
            if(freq[a] == 0) continue;
            
            for(int b = a; b <= 1000; b++){
                if(freq[b] == 0) continue;
                
                int c = sqrt(a*a + b*b);
                
                if(c*c == a*a + b*b && c <= 1000 && freq[c] > 0){
                    
                    if(a == b && freq[a] < 2) continue;
                    if(a == c && freq[a] < 2) continue;
                    if(b == c && freq[b] < 2) continue;
                    
                    return true;
                }
            }
        }
        
        return false;
    }
};