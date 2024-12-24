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
    
    void dfs(int i,int &cnt,vector<int> &visited,map<int,int> &mp,vector<int> &temp){
        if(visited[i]) return ;
        visited[i]=1,cnt++;
        dfs(mp[temp[i]],cnt,visited,mp,temp);
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int ans=0;
        q.push(root);
        TreeNode* dummy=new TreeNode();
        q.push(dummy);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            if(p==dummy){
              if(q.size())
              q.push(dummy);
              vector<int> temp1=temp;
              sort(temp.begin(),temp.end());
              map<int,int> mp;
              for(int i=0;i<temp.size();i++) mp[temp[i]]=i;
              vector<int> visited(temp.size(),0);
              for(int i=0;i<temp.size();i++){
                if(!visited[i] && mp[temp1[i]]!=i){
                    int cnt=0;
                    dfs(i,cnt,visited,mp,temp1);
                    ans+=(cnt-1);
                }
              }
              temp.clear();
              continue;
            }
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
            temp.push_back(p->val);
        }
        return ans;
    }
};