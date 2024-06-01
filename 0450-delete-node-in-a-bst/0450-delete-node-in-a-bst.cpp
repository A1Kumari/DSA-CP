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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(key<root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            //when there is one or no child
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //when two childs
            TreeNode* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val); 
        }
        return root;
    }

    TreeNode* minValueNode(TreeNode* node){
        TreeNode* current = node;
        while(current && current->left != nullptr)
            current = current->left;
        return current;
    }
};