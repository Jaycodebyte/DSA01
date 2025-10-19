/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Jay
      void inorderTraversal(Node* root, vector<int>& inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        

        vector<pair<int,int>> diff;
        for (int val : inorder)
            diff.push_back({abs(val - target), val});
            

        sort(diff.begin(), diff.end());

        vector<int> res;
        for (int i = 0; i < k && i < diff.size(); i++)
            res.push_back(diff[i].second);
            

        return res;
    }
};