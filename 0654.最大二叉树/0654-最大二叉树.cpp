#include <algorithm>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums.begin(), nums.end());
    }

    TreeNode* construct(vector<int>::iterator left, vector<int>::iterator right)
    {
        if(left == right) return nullptr;
        auto maxValIter=max_element(left, right);
        TreeNode* root=new TreeNode(*maxValIter);
        root->left=construct(left, maxValIter);
        root->right=construct(++maxValIter, right);

        return root;
    }
};