class Solution {
  public:
  //Jay
      int getLastDigit(string a, string b) {
        if(a.size() == 1 && a[0] == '0' && b.size() == 1 && b[0] == '0')
            return 1;
        else if(a.size() == 1 && a[0] == '0')
            return 0;
        else if(b.size() == 1 && b[0] == '0')
            return 1;
        
        int num_a = a[a.size()-1] - '0';
        int num_b = 0;
        
        for(int i=0; i<b.size(); i++) {
            num_b = num_b*10 + (b[i]-'0');
            num_b %= 4;
        }
        
        if(num_b == 0)
            num_b = 4;
            
        int res = pow(num_a, num_b);
        res %= 10;
        
        return res;
    }
};