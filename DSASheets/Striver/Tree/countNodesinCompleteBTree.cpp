/*
- Formula is (2^TreeLevel - 1). Only works for perfect tree.
- To determine if its a perfect tree, go all the way down and count the nodes on left and right side, 
  If they match, its a perfect tree and our formula applies.

- If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
- When we have our left and right heights, we do (1 + left + right)

- If we reach null, return 0
- C++ note: 1 << n is the same as raising 2 to the power n, or 2^n
*/
class Solution
{
    int left_height(TreeNode *root)
    {
        int h = 1;
        while (root->left)
            root = root->left, h++;
        return h;
    }

    int right_height(TreeNode *root)
    {
        int h = 1;
        while (root->right)
            root = root->right, h++;
        return h;
    }

public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        if (root)
        {
            int l = left_height(root), r = right_height(root);
            if (l == r)
                return (1 << l) - 1;

            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        return count;
    }
};