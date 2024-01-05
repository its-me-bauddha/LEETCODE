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
        // **************** MORRIS TRAVERSAL *************************// 

        /// T.C = O(n) && S.C  = O(1)
        // it is simple inoder traversal only difference in morris and inorder is the space complexity :
        // S.C of indoer. -> O(n). while
        // S.C of morris  -> O(1)
        // T.C of both traversal is same i.e  -> O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode * curr = root;

        while(curr ){
            // left node is NULL , then visit it , and go right
            if(curr -> left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // left node is NOT NULL
            else{
                // find the inorder predecessor
                TreeNode* pred = curr->left;
                while(pred ->right != curr && pred ->right){
                    pred = pred->right;
                }

                // if right node is null ,then go left after establshing the link from pred to curr
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    // left is already visited , Go right after visiting curr node, while removing the link
                    pred ->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return ans;
    }
};