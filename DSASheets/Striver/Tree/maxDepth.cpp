// 6. Maximum Depth in Binary Tree
//   - Using Recursion (T.C = O(N))
int maxDepth(TreeNode *root)
{
    if (root)
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    return 0;
}

//   - Using Level Order Traversal (T.C = O(N))
int maxDepth(TreeNode *root)
{
    int depth = 0;
    if (root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                root = q.front(), q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            depth++;
        }
    }
    return depth;
}