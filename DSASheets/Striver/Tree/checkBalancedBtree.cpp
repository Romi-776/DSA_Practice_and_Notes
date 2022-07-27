// (Height difference of left and right subtree should not be greater than 1)
// 7. Check for Balanced Binary Tree
//   - Naive approach (O(N^2))
//   # using level order traversal and height of binary tree, checking for each node the abs diff of
//   # left and right subtree
int height(TreeNode *root)
{
    if (root)
        return 1 + max(height(root->left), height(root->right));
    return 0;
}

bool isBalanced(TreeNode *root)
{
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
                int h = abs(height(root->left) - height(root->right));

                if (h > 1)
                    return false;

                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
    }
    return true;
}

//   - Optimized approach (O(N))
//   # using the concept of height of tree, while checking the total height of the tree
//   # i'm checking that does the left or right subtree gave a reponse which occurred due
//   # to imbalance of binary tree
int height(TreeNode *root)
{
    if (root)
    {
        int l = height(root->left), r = height(root->right);
        // when we get -1, i.e., the height diff > 1 so not balanced
        if (l == -1 or r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;
        return 1 + max(l, r);
    }
    return 0;
}

bool isBalanced(TreeNode *root)
{
    return height(root) != -1;
}