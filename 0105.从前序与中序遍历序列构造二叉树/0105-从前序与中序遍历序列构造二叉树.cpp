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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* build(
        vector<int>::iterator preBegin, vector<int>::iterator preEnd, 
        vector<int>::iterator inBegin, vector<int>::iterator inEnd)
    {
        if(preBegin >= preEnd || inBegin >= inEnd) return nullptr;

        int rootVal=*preBegin;
        TreeNode* root=new TreeNode(rootVal);

        auto rootInorderIter=find(inBegin, inEnd, rootVal);
        int leftSize=rootInorderIter-inBegin;
        auto newPreEnd=preBegin+leftSize+1;

        root->left=build(++preBegin, newPreEnd, inBegin, rootInorderIter);
        root->right=build(newPreEnd, preEnd, ++rootInorderIter, inEnd);
        return root;
    }
};