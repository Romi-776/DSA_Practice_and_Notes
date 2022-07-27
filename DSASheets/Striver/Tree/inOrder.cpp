// (left, root, right)
// 2. InOrder Traversal
//   - Recursive (T.C = O(N), S.C = O(N))
//     Similar approach as above but shifting steps to left, root, and right

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