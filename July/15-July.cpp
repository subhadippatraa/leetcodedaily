/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mapp;
        unordered_map<int, bool> checkRoot;

        for (auto i : descriptions) {
            int parentVal = i[0];
            int childVal = i[1];
            int isLeft = i[2];

            TreeNode* parentNode = NULL;
            TreeNode* childNode = NULL;
            // this is for the Parent

            if (mapp.find(parentVal) != mapp.end()) // ParentNode Found
            {
                parentNode = mapp[parentVal];
            } else // Parent Node Not found so we create a Node
            {
                parentNode = new TreeNode(parentVal);
                mapp[parentVal] = parentNode; // Update the map with new Node
            }

            // //this is for the child

            if (mapp.find(childVal) != mapp.end()) // childNode Found
            {
                childNode = mapp[childVal];
            } else // Parent Node Not found so we create a Node
            {
                childNode = new TreeNode(childVal);
                mapp[childVal] = childNode; // Update the map with new Node
            }

            if (isLeft)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
            // update the checkRoot mapp
            checkRoot[childVal] = true;
        }
        TreeNode* root = NULL;
        for (auto& [val, node] : mapp) {
            if (!checkRoot[val])
                root = node;
        }
        return root;
    }
};