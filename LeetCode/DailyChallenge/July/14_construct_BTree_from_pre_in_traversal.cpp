// Construct Binary Tree from Preorder and Inorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// T.C = O(N^2), S.C = O(N^2)
/*
INTUITION
https://www.youtube.com/watch?v=ihj4IQGZ2zc

COULD BE OPTIMIZED FURTHER.
*/
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() and inorder.size())
        {
            vector<int> p, in;
            TreeNode *root = new TreeNode(preorder[0]);
            int indx = 0;
            for (; indx < inorder.size(); indx++)
                if (preorder[0] == inorder[indx])
                    break;
            for (int i = 1; i <= indx; i++)
                p.push_back(preorder[i]), in.push_back(inorder[i - 1]);

            root->left = buildTree(p, in);
            p.clear(), in.clear();

            for (int i = indx + 1; i < inorder.size(); i++)
                p.push_back(preorder[i]), in.push_back(inorder[i]);
            root->right = buildTree(p, in);

            return root;
        }
        return NULL;
    }
};