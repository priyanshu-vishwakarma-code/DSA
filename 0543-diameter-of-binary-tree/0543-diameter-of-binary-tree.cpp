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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }

    int solve(TreeNode* root){
        if (root==NULL) return 0;
        int leftheight = solve(root->left);
        int rightheight = solve(root->right);
        diameter = max(diameter, leftheight + rightheight);
        return max(leftheight , rightheight) + 1;
    }
};