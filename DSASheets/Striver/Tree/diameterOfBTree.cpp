// (Using the concept of Height of a Binary tree, we're keeping track of the max_value of l+r which is the diameter of the current node)
// 8. Diameter of Binary Tree
//   # maximum passed by reference in order to store the max
//   # diameter till now
int dia(TreeNode *root, int &maximum)
{
    if (root)
    {
        int l = dia(root->left, maximum);
        int r = dia(root->right, maximum);
        maximum = max(maximum, l + r);
        return 1 + max(l, r);
    }
    return 0;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int max = 0;
    dia(root, max);
    return max;
}