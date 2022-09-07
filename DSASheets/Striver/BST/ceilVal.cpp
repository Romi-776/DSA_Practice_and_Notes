// Similarly, we can find the floor of a value in a BST
// and can implement in recursive manner

// T.C = O(log(n)), S.C = O(1)
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    int ans = INT_MAX;
    while (root)
    {
        if (root->data < input)
            root = root->right;
        else
            ans = min(ans, root->data), root = root->left;
    }

    return (ans == INT_MAX ? -1 : ans);
}