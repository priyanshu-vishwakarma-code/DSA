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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->val == subRoot->val){
                if(isSameTree(curr,subRoot)) return true;
            }

            if(curr->left!=NULL)  q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;

        //check root
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        
        bool leftcheck = isSameTree(p->left , q->left);
        bool rightcheck = isSameTree(p->right , q->right);

        return leftcheck && rightcheck;
    }

};