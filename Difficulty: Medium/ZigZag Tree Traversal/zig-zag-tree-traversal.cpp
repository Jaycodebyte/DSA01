/*
class Node {
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
       vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> currentLevel, nextLevel;
        bool leftToRight = true;
        currentLevel.push(root);

        while (!currentLevel.empty()) {
            Node* node = currentLevel.top();
            currentLevel.pop();
            result.push_back(node->data);

            if (leftToRight) {
                if (node->left) nextLevel.push(node->left);
                if (node->right) nextLevel.push(node->right);
            } else {
                if (node->right) nextLevel.push(node->right);
                if (node->left) nextLevel.push(node->left);
            }

            if (currentLevel.empty()) {
                leftToRight = !leftToRight;
                swap(currentLevel, nextLevel);
            }
        }
        return result;
    }
};