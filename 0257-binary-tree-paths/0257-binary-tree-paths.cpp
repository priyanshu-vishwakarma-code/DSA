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
    void recursion(TreeNode* root, vector<string>&finalans, string ans){
        // base case
        if(root==NULL){
            return;
        }


        //current
        string val = to_string(root->val);
        if(ans=="") ans = ans + val;
        else ans = ans + "->" + val;

        if(root->left==NULL && root->right==NULL){
            finalans.push_back(ans);
            return;
        }

        //left
        recursion(root->left, finalans, ans); 

        //right
        recursion(root->right, finalans, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        vector<string>finalans;
        string ans = "";
        
        recursion(root, finalans, ans);
        
        return finalans;
    }
};