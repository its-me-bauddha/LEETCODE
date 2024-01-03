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
    bool isValidBSTHelper(TreeNode* root , long long int lowerBound,
     long long int upperBound){
        if(root == NULL) return true;

        if((root ->val > lowerBound && root->val < upperBound) &&
           (isValidBSTHelper(root->left ,lowerBound,root -> val)) && 
            (isValidBSTHelper(root->right ,root -> val,upperBound))){
           return true;
        }
        else{
            return false;
        } 
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound = -4294967296;
         long long int upperBound = 4294967296;

        return isValidBSTHelper(root ,lowerBound,upperBound);   
    }
};