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
    int maxVal(TreeNode * root){
       TreeNode * temp = root;
       if(temp == NULL) return -1;
       while(temp->right != NULL){
           temp = temp->right;
       }
       return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root -> val == key){
            // 4 cases 

            //leaf node
            if(root ->right == NULL && root ->left == NULL){
                delete root ;
                return NULL;
            }
            else if(root ->right != NULL && root ->left ==NULL){
                TreeNode* rightChild = root ->right;
                delete root;
                return rightChild;
            }else if(root ->right == NULL && root ->left !=NULL){
                TreeNode* leftChild = root ->left;
                delete root;
                return leftChild;
            }else{
                // both node != NULL

                int inOrderPre = maxVal(root ->left);
                root -> val = inOrderPre;
                root ->left = deleteNode(root->left,inOrderPre);
                return root;
            }

        }else if(root -> val > key){
            root -> left = deleteNode(root ->left,key);
        }
        else if(root -> val < key){
            root ->right = deleteNode(root ->right,key);
        }
        
        return root ;
        
    }
};