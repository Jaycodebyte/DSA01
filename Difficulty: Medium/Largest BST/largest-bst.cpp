/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  //jay
   struct Info {
        int minVal, maxVal, size;
    };
    
    Info solve(Node* root, int &ans) {
        if(!root) return {INT_MAX, INT_MIN, 0};
        
        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);
        
        if(root->data > left.maxVal && root->data < right.minVal) {
            
            int currSize = left.size + right.size + 1;
            ans = max(ans, currSize);
            
            return {
                min(root->data, left.minVal),
                max(root->data, right.maxVal),
                currSize
            };
        }
        
        return {INT_MIN, INT_MAX, max(left.size, right.size)};
    }
    
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};