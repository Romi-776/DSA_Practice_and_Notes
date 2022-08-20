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

// PRE-ORDER MORRIS TRAVERSAL
// 🌳 1st case: if left is null, print current node and go right
// 🌳 2nd case: before going left, make right most node on left subtree connected to current node, print the curr node, then go left of curr node
// 🌳 3rd case: if thread is already pointed to current node, then remove the thread

vector<int> preorderTraversal(TreeNode *curr)
{
    vector<int> ans;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *last = curr->left;
            while (last->right and last->right != curr)
                last = last->right;
            if (last->right)
            {
                last->right = NULL;
                curr = curr->right;
            }
            else
            {
                last->right = curr, ans.push_back(curr->val);
                curr = curr->left;
            }
        }
        else
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}