// (left, right, root)
// 3. PostOrder Traversal
//   - Recursive (T.C = O(N), S.C = O(N))

//   # Similar to below approach we're just using an extra stack for reversal of the nodes at the end
//   - Iterative (Using 2 stacks) (T.C = O(N), S.C = O(N))
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> nodes;

    if (root)
    {
        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (st1.size())
        {
            root = st1.top(), st1.pop();
            st2.push(root);

            if (root->left)
                st1.push(root->left);
            if (root->right)
                st1.push(root->right);
        }

        while (st2.size())
        {
            nodes.push_back(st2.top()->val);
            st2.pop();
        }
    }
    return nodes;
}

// add current node into stack, until the stack is not empty, store the topmost node then add the left of current
// node into stack and then the right of current node into stack and then before printing, reverse the container
// in which the nodes are stored for printing purposes
// Iterative (Using 1 stack) (T.C = O(N), S.C = O(N))
vector<int> postorderTraversal(TreeNode *root)
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

            if (root->left != NULL)
                st.push(root->left);
            if (root->right != NULL)
                st.push(root->right);
        }
        reverse(nodes.begin(), nodes.end());
    }
    return nodes;
}