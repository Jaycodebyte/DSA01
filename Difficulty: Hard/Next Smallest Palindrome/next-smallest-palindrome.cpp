class Solution {
  public:
  //Jay
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        
        vector<int> res = num;
        
        int i = n/2 - 1;
        int j = (n % 2) ? n/2 + 1 : n/2;
        
        bool leftSmaller = false;
        
        while(i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }
        
        if(i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }
        
        while(i >= 0) {
            res[j] = res[i];
            i--;
            j++;
        }
        
        if(leftSmaller) {
            int carry = 1;
            
            i = n/2 - 1;
            
            if(n % 2 == 1) {
                res[n/2] += carry;
                carry = res[n/2] / 10;
                res[n/2] %= 10;
                j = n/2 + 1;
            } else {
                j = n/2;
            }
            
            while(i >= 0 && carry) {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;
                
                res[j] = res[i];
                i--;
                j++;
            }
        }
        
        if(res[0] == 0) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            ans[n] = 1;
            return ans;
        }
        
        return res;
    }
};