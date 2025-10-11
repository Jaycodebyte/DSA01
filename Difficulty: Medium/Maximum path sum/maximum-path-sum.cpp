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
     //jay
     int maxSum;
    int dfs(Node* root) {
        if (!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->data + left + right);
        return root->data + max(left, right);
    }

    int findMaxSum(Node* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};