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
    TreeNode* insert(TreeNode* root,int v){
        if(root==nullptr)return new TreeNode(v);
        if(root->val>v){
            root->left = insert(root->left,v);

        }
        else{
            root->right = insert(root->right,v);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for(int i =0;i<preorder.size();i++){
            root = insert(root,preorder[i]);
        }
        return root;
    }
};