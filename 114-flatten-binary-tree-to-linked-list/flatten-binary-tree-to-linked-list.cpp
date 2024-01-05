/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
       TreeNode* curr = root;
       while(curr){
           // left node is NOT NULL
           if(curr->left){
               // find the predecessor of the curr node
               TreeNode* pred = curr->left;
               while(pred->right)
                   pred = pred->right;
               // attaching the pred right to curr right
               pred->right = curr->right;
               curr ->right = curr->left;
               curr->left = NULL;
               
           }
               // if left is NULL , kuchh nhi karna sirf aage bad jao
                curr = curr->right;
       } 
      
    }
};