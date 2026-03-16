/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  //Jay
     int dfs(Node* node, long long currSum, int k, unordered_map<long long,int> &mp){
        if(!node) return 0;
        
        currSum += node->data;
        
        int count = 0;
        
        if(mp.find(currSum - k) != mp.end())
            count += mp[currSum - k];
            
        mp[currSum]++;
        
        count += dfs(node->left, currSum, k, mp);
        count += dfs(node->right, currSum, k, mp);
        
        mp[currSum]--;  
        
        return count;
    }
  
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        
        return dfs(root, 0, k, mp);
        
    }
};