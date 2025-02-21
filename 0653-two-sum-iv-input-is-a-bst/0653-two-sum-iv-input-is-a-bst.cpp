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
    void dfs(TreeNode* root,bool &s,set<int> &st,int k){
        if(st.find(root->val)!=st.end()) s=1;
        st.insert(k-(root->val));
        if(root->left!=NULL) dfs(root->left,s,st,k);
        if(root->right!=NULL) dfs(root->right,s,st,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return 0;
        set<int> st;
        bool s=0;
        dfs(root,s,st,k);
        return s;
    }
};