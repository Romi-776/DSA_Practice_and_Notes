// Iterative - T.C = O(log(n)), S.C = O(1)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (root->val == val)
                break;
            else if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};

// Recursive - T.C = O(log(n)), S.C = O(log(n))
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root)
    {
        if (root->val == val)
            return root;
        if (root->val < val)
            return searchBST(root->right, val);
        return searchBST(root->left, val);
    }
    return NULL;
}