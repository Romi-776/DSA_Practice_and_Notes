// (Intuition: Taking only 3 nodes and assuming that in preorder root comes first and in inorder and postorder root comes 2nd and 3rd respectively)
// 4. PreOrder, InOrder, PostOrder all in one Traversal
//  add current node to stack as a pair of <node, 1> now while the stack isn't empty get the topmost node and pop it
//  for pre (time=1) : push into pre, incre time, push into stack, check for left, add if present
//  for in (time=2) : push into in, incre time, push into stack, check for right, add if present
//  for post (time=3) : just push into post
void preInPostTraversal(TreeNode *root)
{
    // stores node, and no. of times it occurred
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    vector<int> pre, in, post;

    while (st.size())
    {
        auto it = st.top();
        st.pop();

        // preorder, increment, push, left
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++, st.push(it);

            if (it.first->left)
                st.push({it.first->left, 1});
        }
        // inorder, increment, push, right
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++, st.push(it);

            if (it.first->right)
                st.push({it.first->right, 1});
        }
        // postorder, don't push again into stack
        else
            post.push_back(it.first->val);
    }
}