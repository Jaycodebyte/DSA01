/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:

        int longestConsecutive(Node* root)
    {
        //Code here
        int ans = -1;
        solve(root, root->data, 1, ans);
        return ans;
    }
    
    void solve(Node* root, int mx, int l, int& ans){
        if(!root){
            return;
        }
        
        if(root->left){
            if(root->left->data == mx+1){
                ans = max(ans, l+1);
                solve(root->left, mx+1, l+1, ans);
            }
            else{
                solve(root->left, root->left->data, 1, ans);
            }
        }
        if(root->right){
            if(root->right->data == mx+1){
                ans = max(ans, l+1);
                solve(root->right, mx+1, l+1, ans);
            }
            else{
                solve(root->right, root->right->data, 1, ans);
            }
        }
        
    }
};