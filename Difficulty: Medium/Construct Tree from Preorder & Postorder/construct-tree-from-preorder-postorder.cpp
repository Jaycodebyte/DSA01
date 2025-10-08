/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int preIndex = 0;

public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        return construct(pre, post, 0, post.size() - 1);
    }

private:
    Node* construct(vector<int>& pre, vector<int>& post, int l, int r) {
        if (preIndex >= pre.size() || l > r) return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == r || preIndex >= pre.size()) return root;

        int idx = l;
        while (idx <= r && post[idx] != pre[preIndex]) idx++;

        if (idx <= r) {
            root->left = construct(pre, post, l, idx);
            root->right = construct(pre, post, idx + 1, r - 1);
        }

        return root;
    }
};