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
    int ans;
    void inorder(TreeNode* root, int k, int& n){
        if(root==nullptr)return ;
        inorder(root->left,k,n);
        if(n==k)ans=root->val;
        n= n+1;
        inorder(root->right,k,n);

    }
    int kthSmallest(TreeNode* root, int k) {
        int n =1;
        inorder(root,k,n);
        return ans;
    }
};