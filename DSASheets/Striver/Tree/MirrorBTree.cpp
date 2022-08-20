/*
    Firstly changing all the left subtrees and then right and then the current node so that everything will
    be adjusted accordingly on the deeper level before working on upper levels.
*/
class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        if (node)
        {
            mirror(node->left);
            mirror(node->right);
            swap(node->right, node->left);
        }
    }
};