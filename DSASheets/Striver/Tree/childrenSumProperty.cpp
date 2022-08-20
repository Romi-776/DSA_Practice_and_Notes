/*
Children sum property = Every node should have the value equal to the sum of its child nodes (if they have any)

Problem : We're given a tree and we need to convert the tree into a tree that follows children sum property.

APPROACH
 We're going deeper first and checking that does the curr node have value less or greater than its children
 if yes then change its value to children's val otherwise set the val of children = curr node's val
 and then go deeper while following this approach. When coming upward, update the curr node's val = children's val sum

T.C = O(N), S.C = O(H)
*/
void changeTree(BinaryTreeNode<int> *root)
{
    if (root)
    {
        int children = 0;
        if (root->left)
            children += root->left->data;
        if (root->right)
            children += root->right->data;

        if (children >= root->data)
            root->data = children;
        else
        {
            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }

        changeTree(root->left), changeTree(root->right);

        int lr = 0;
        if (root->left)
            lr += root->left->data;
        if (root->right)
            lr += root->right->data;
        if (root->left or root->right)
            root->data = lr;
    }
}