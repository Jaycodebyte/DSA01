class Solution {
  public:
  //Jay
    int smallestSubstring(string s) {
        int n = s.size();
         int ans = 1e9;
         int i =0, j =0;
         unordered_map<char , int> mp;
          while(j<n){
              mp[s[j]]++;
               if( mp.size()==3){
   ans = min( ans , j-i+1);
   while(i<j && mp.size()==3){
                         mp[s[i]]--;
                          if(mp[s[i]]==0) {
                               mp.erase(s[i]);
                          
                          }
                           i++;
                           if( mp.size()==3){
                                ans = min( ans , j-i+1);
                           }
                           else break;
                     }
               }
               j++;
          }
          if( ans == 1e9) return -1;
           return ans ;  
    }
};
