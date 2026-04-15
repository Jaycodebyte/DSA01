class Solution {
  public:
  //Jay
      string URLify(string &s) {
        string ans;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int j=s.size()-1;
        while(i<=j){
            if(s[i]==' '){
                ans+="%20";
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};