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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode* build(
        vector<int>::iterator inBegin, vector<int>::iterator inEnd,
        vector<int>::iterator postBegin, vector<int>::iterator postEnd
    ) 
    {    
        if(inBegin >= inEnd || postBegin >= postEnd) return nullptr;

        int rootVal=*(postEnd-1);
        TreeNode* root=new TreeNode(rootVal);

        auto rootInorderIter = find(inBegin, inEnd, rootVal);
        int leftSize=rootInorderIter-inBegin;
        auto newMidPos=postBegin+leftSize;

        root->left=build(inBegin, rootInorderIter, postBegin, newMidPos);
        root->right=build(++rootInorderIter, inEnd, newMidPos, --postEnd);

        return root;
    }
};