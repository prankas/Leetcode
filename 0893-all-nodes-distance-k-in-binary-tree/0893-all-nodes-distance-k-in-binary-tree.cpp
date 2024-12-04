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
    map<TreeNode*, int> numbers;

    void dfs(TreeNode* curr, TreeNode* target) {
        if (curr == target) {
            numbers[curr] = 1;
            return;
        }
        if (curr->left != NULL) {
            dfs(curr->left, target);
            if (numbers[curr->left] > 0)
                numbers[curr] = numbers[curr->left] + 1;
        }
        if (curr->right != NULL) {
            dfs(curr->right, target);
            if (numbers[curr->right] > 0)
                numbers[curr] = numbers[curr->right] + 1;
        }
    }

    void dfs1(TreeNode* curr, vector<int>& ans, int k) {
        if (numbers[curr] == k + 1) {
            ans.push_back(curr->val);
        }
        if (curr->left != NULL) {
            if (numbers[curr->left] == 0) {
                numbers[curr->left] = numbers[curr] + 1;
            }
            dfs1(curr->left, ans, k);
        }
        if (curr->right != NULL) {
            if (numbers[curr->right] == 0) {
                numbers[curr->right] = numbers[curr] + 1;
            }
            dfs1(curr->right, ans, k);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target);
        vector<int> ans;
        dfs1(root, ans, k);
        return ans;
    }
};

/*class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    }
};*/