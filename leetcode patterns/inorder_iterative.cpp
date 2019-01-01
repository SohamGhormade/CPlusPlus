#include <vector>
#include<stack>

using namespace std;
  //Definition for a binary tree node.
   class TreeNode {
      public :
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) { val = x; }
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> nodes;

        if(root == NULL) return inorder;

        while(root != NULL || !nodes.empty()){
            //push left children if available
            while(root != NULL){
                nodes.push(root);
                root = root->left;
            }

            //retrieve top node and store its right child if exists
            root = nodes.top();
            nodes.pop();

            inorder.push_back(root->val);
            root = root->right;
        }

        return inorder;
    }
};