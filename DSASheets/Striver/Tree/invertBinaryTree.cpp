// https://leetcode.com/problems/invert-binary-tree/

// INVERT BINARY TREE

// Recursive approach
// T.C = O(N), S.C = O(H) here H = Height of the tree
TreeNode *invertTree(TreeNode *root)
{
    if (root)
    {
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}

// Iterative approach
// T.C = O(N), S.C = O(W) here W = Width of the tree
TreeNode *invertTree(TreeNode *root)
{
    TreeNode *newRoot = root;
    if (root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            root = q.front();
            q.pop();
            swap(root->left, root->right);

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }

    return newRoot;
}