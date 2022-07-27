// (T.C = O(N), S.C = O(N))
// 10. Check if two trees are Identical or Not
//   - My messy code with simple logic (similar to preorder traversal)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // if two nodes are null, i.e., equal then they are same
    if (p == q)
        return true; // so no need to check further

    // otherwise check that is there any case where there's one node is null and
    // the other one is not or if both nodes are not null then their values should be same
    if ((p and !q) or (q and !p) or p->val != q->val)
        return false; // in any of the above cases those trees are not identical

    // otherwise we have to check the left and right part of the remaining tree
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}

//   - same logic, clear code (preorder traversal)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL or q == NULL)
        return (p == q);
    return (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}
