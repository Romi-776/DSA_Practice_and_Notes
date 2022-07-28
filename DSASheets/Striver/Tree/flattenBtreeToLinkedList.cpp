// SOL - 1 | T.C = O(2*N), S.C = O(2*N)
// My naive solution using preorder traversal
// To store all the nodes occurred in preorder traversal
vector<TreeNode *> v;

void pre(TreeNode *root)
{
    if (root)
    {
        v.push_back(root);
        pre(root->left);
        pre(root->right);
    }
}

public:
void flatten(TreeNode *root)
{
    // perform preorder traversal
    pre(root);

    // if we have some nodes that are traversed
    if (v.size())
    {
        // then we'll connect each node with the next node that occurred in preorder traversal
        // and the links between them will be made using the right pointer and left pointer for
        // each node will be null
        root = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            root->right = v[i];
            root->left = NULL;
            root = v[i];
        }
    }
}

// SOL - 2 | T.C = O(N), S.C = O(N)
// Traversing in right left root manner and maintaining
// a prev pointer that stores the last processed node and
// points the current node's right to last processed node
// and left as NULL
TreeNode *prev = NULL;

public:
void flatten(TreeNode *root)
{
    if (root)
    {
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
}