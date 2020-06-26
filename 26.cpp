//Sum Root to Leaf Numbers
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
    void DFS(TreeNode *r,string s,int &ans){
        if(!r)return;
        s+=to_string(r->val);
        if(!r->left&&!r->right)ans+=stoi(s);
        DFS(r->left,s,ans);
        DFS(r->right,s,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        string s = "";
		int ans = 0;
        DFS(root,s,ans);
        return ans;
    }
};  
