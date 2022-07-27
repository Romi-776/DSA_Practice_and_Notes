// (root, left, right)
// 1. PreOrder Traversal
//   - Recursive (T.C = O(N), S.C = O(N))
void traverse(TreeNode *root, vector<int> &nodes)
{
    if (root)
    {
        nodes.push_back(root->val);
        traverse(root->left, nodes);
        traverse(root->right, nodes);
    }
}

// add current node into stack, until the stack is not empty, print the topmost node then add the right of current
// node into stack and then the left of current node into stack
//  iterative (T.C. = O(N), S.C = O(N))
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    if (root)
    {
        stack<TreeNode *> st;
        st.push(root);

        while (st.size())
        {
            root = st.top(), st.pop();

            nodes.push_back(root->val);
            if (root->right)
                st.push(root->right);
            if (root->left)
                st.push(root->left);
        }
    }
    return nodes;
}