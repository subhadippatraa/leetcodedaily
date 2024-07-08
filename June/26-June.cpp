
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& arr) {
        if (root == NULL)
            return;
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }

    TreeNode* balance(int start, int end, vector<TreeNode*>& arr) {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        root->left = balance(start, mid - 1, arr);
        root->right = balance(mid + 1, end, arr);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<TreeNode*> arr;

        inorder(root, arr);
        int n = arr.size();
        return balance(0, n - 1,arr);
    }
};