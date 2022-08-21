/*
INTUITION
At the end of each part of postorder, the node present is the root node of curr subtree.
Using that node we can find the left and right subtree nodes
Dividing the nodes of inorder with respect to left and right subtrees
Dividing the nodes of postorder from the start with respect to the no. of nodes in left subtree and and the no. of nodes in right tree
*/

class Solution
{
    TreeNode *build(vector<int> &in, vector<int> &po, int is, int ie, int ps, int pe, unordered_map<int, int> &mp)
    {
        // out of bound
        if (is > ie or ps > pe)
            return NULL;

        // creating root of curr sub tree
        TreeNode *root = new TreeNode(po[pe]);
        // finding the index of curr root node in inorder
        int root_indx = mp[po[pe]];

        // no. of elements in left subtree
        int left = root_indx - is;

        // left subtree
        root->left = build(in, po, is, is + root_indx - 1, ps, ps + left - 1, mp);

        // right subtree
        root->right = build(in, po, root_indx + 1, ie, ps + left, pe - 1, mp);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // mapping all inorder nodes with their index
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return build(inorder, postorder, 0, n - 1, 0, n - 1, mp);
    }
};