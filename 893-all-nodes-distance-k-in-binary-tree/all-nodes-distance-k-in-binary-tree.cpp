/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        mp[root]=nullptr;
        unordered_set<TreeNode*>vis;
        parents(root,mp);
        vector<int>res;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            vis.insert(node);
            if(d==k)res.push_back(node->val);
            if(node->left && !vis.count(node->left)){
                q.push({node->left,d+1});
            }
            if(node->right && !vis.count(node->right)){
                q.push({node->right,d+1});
            }
            if(mp[node] && !vis.count(mp[node])){
                q.push({mp[node],d+1});
            }
        }
        return res;
    }
};