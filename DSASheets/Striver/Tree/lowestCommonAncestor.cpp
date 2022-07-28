// firstly, finding any of the p or q node
// if any of them found then checking the remaining left 

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root)
    {
        if (root == p or root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == right)
            return left;
        else if (left != NULL and right != NULL)
            return root;
        else if (left != NULL)
            return left;
        else
            return right;
    }
    return NULL;
}