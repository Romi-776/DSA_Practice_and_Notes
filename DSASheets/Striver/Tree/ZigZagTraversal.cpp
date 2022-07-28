// (T.C = O(N), S.C = O(N))
// 11. Zig-Zag or Spiral Traversal in Binary Tree
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    // if we have atleast 1 node
    if (root)
    {
        // doing the same level order traversal
        queue<TreeNode *> q;
        q.push(root);

        // it will tell us that either we need to insert the current node of
        // the queue from the back of the vector or from the front making it
        // zizag traversal
        bool leftToRight = true;

        while (q.size())
        {
            int sz = q.size();
            vector<int> nodes(sz);

            for (int i = 0; i < sz; i++)
            {
                root = q.front(), q.pop();

                // for left to right we're just inserting it to the back of the vector
                // otherwise we're inserting it to the front by calculating its index
                int pos = leftToRight ? i : sz - i - 1;
                nodes[pos] = root->val;

                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            ans.push_back(nodes);

            // reversing the direction of traversal
            leftToRight = !leftToRight;
        }
    }
    return ans;
}