// (left, root, right)
// 2. InOrder Traversal
//   - Recursive (T.C = O(N), S.C = O(N))

//     # go towards the left of the current node (while pushing the current node into stack) until we're not at NULL
//     # when at NULL, if the stack is empty then there's no node so stop, otherwise pick the topmost node, print it,
//     # and then go towards the right of the topmost node, repeat these steps until the stack is not empty
//     - Iterative (T.C = O(N), S.C = O(N))
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    if (root)
    {
        stack<TreeNode *> st;
        while (true)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                    break;

                root = st.top(), st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
    }
    return nodes;
}

// MORRIS INORDER TRAVERSAL
// 🌳 1st case: if left is null, print current node and go right
// 🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left of curr node
// 🌳 3rd case: if thread is already pointed to current node, print curr node, remove the thread, then go to right of curr node

vector<int> inorderTraversal(TreeNode *curr)
{
    vector<int> ans;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *last = curr->left;
            while (last->right and last->right != curr) last = last->right;
            if (last->right)
            {
                last->right = NULL, ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                last->right = curr;
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