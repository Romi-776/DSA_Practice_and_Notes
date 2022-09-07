/*
OPTIMIZING THE BELOW WRITTEN APPROACH

INTUITION:
As we have a BST, therefore there are a couple possibilities
1. One node is left of root and other on the right - then current node is LCA
2. Both the nodes are on left side of root - then go towards left side to find LCA
3. Both the nodes are on right side of root - then go towards right side to find LCA
4. One of the node equals root - then the curr node is LCA
*/

// T.C = O(H), S.C = O(1) // if we use iterative method
// S.C = O(H) // if we use recursive method
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root)
    {
        int a = p->val, b = q->val, val = root->val;
        if (val == a or val == b)
            return root;
        else if ((a < val and b > val) or (a > val and b < val))
            return root;
        else if (a < val and b < val)
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
    return NULL;
}

/*
 Naive
 firstly, finding any of the p or q node
 if any of them found then checking the remaining left
 if in the remaining left we found something then we're returning root
 otherwise whichever that's not NULL and NULL if we have only one or no node out of p and q
*/
// T.C = O(N), S.C = O(H)
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root)
    {
        // we found at least one of the two nodes
        if (root == p or root == q)
            return root;

        // checking the left and right subtrees
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // some of the cases explained above
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