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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        TreeNode* dummy=new TreeNode(INT_MIN);
        if(root==NULL) return {};
        q.push(root);
        q.push(dummy);
        int m=INT_MIN;
        while(!q.empty()){
            TreeNode* nd=q.front();
            q.pop();
            if(nd==dummy){
                if(q.size()) q.push(dummy);
                ans.push_back(m);
                m=INT_MIN;
                continue;
            }
            m=max(m,nd->val);
            if(nd->left!=NULL) q.push(nd->left);
            if(nd->right!=NULL) q.push(nd->right);
        }
        return ans;
    }
};