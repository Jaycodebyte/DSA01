/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
     vector<int> verticalSum(Node* root) {
        
        queue<pair<Node*,int>>que;
    
        if(root==NULL){
            return {};
        }
        map<int,int>mpp;
        que.push({root,0});
        while(!que.empty()){
            int lineNo=que.front().second;
            Node* node=que.front().first;
            mpp[lineNo]+=node->data;
            if(node->left!=NULL){
                que.push({node->left,lineNo-1});
                
            }
            if(node->right!=NULL){
                que.push({node->right,lineNo+1});
                
            }
            que.pop();
        }
        vector<int>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};