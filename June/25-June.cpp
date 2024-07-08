
class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root != NULL) {
            bstToGst(root->right);
            root->val += sum;
            sum = root->val;
            bstToGst(root->left);
        }
        return root;
    }
};