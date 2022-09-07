// firstly, finding any of the p or q node
// if any of them found then checking the remaining left
// if in the remaining left we found something then we're returning root
// otherwise whichever that's not NULL and NULL if we have only one or no node out of p and q

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

/*
NAIVE APPROACH:
We can first find the path to both the nodes using any traversal
and then by comparing them we can get to know the LCA of the two nodes.
T.C = O(4*N) // for both the Traversals and comparing of nodes in the path
S.C = O(4*N) // for storing the path of both the nodes and their recursive stacks
*/