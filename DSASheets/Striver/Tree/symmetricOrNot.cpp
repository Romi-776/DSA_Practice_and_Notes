// https://leetcode.com/problems/symmetric-tree/

// T.C = O(N), S.C = O(N)
// Checking that the value of corresponding left and right subtrees are equal
// and the left subtree is equal to the right subtree
class Solution
{
    // assuming that initially the tree is symmetric
    bool symmetric = true;

    // checking left and right subtrees
    void check(TreeNode *l, TreeNode *r)
    {
        // if until now the tree is symmetric
        if (symmetric)
        {
            // and there exists a left and a right subtree
            if (l and r)
            {
                // does both nodes have same value
                symmetric = (l->val == r->val);

                // checking left and right subtrees of current subtree's
                check(l->left, r->right);
                check(l->right, r->left);
                return;
            }
            // otherwise check that both nodes are equal (in case of NULL)
            symmetric = (l == r);
        }
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            // checking left and right subtrees of root node
            check(root->left, root->right);
        }

        return symmetric;
    }
};