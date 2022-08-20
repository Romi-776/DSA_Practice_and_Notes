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
        // zigzag traversal
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

// REAL ZIGZAG TRAVERSAL USING 2 STACKS
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root) {
        // 2 stacks to store nodes while left or right traversal
        stack<TreeNode *> dqL, dqR;

        // currently going from left to right
        TreeNode *cur = root;
        dqL.push(cur);

        // until we have atleast 1 node in any of the stacks
        while (dqL.size() || dqR.size())
        {
            // to store the nodes at current level
            vector<int> curLevel;

            // if we have nodes in leftToRight stack
            while (dqL.size())
            {
                // so get the data from the stack and fill it into currentLevel nodes
                // these nodes are given by the current stack in leftToRight manner
                cur = dqL.top();
                dqL.pop();
                curLevel.push_back(cur->val);
                // and we need to also add these nodes into rightToLeft stack in leftToRight manner
                // so that  while popping they must give the data in rightToLeft manner
                if (cur->left) dqR.push(cur->left);
                if (cur->right) dqR.push(cur->right);
            }

            // if we have some data in currentLevel vector then we need to add the data into answers
            // and clear the data so that it can again be filled for the next iteration
            if (curLevel.size() > 0)
            {
                ans.push_back(curLevel);
                curLevel.clear();
            }

            // similar to above comments but minor changes in the approach
            // of inserting data into other stack
            while (dqR.size())
            {
                cur = dqR.top();
                dqR.pop();
                curLevel.push_back(cur->val);
                if (cur->right) dqL.push(cur->right);
                if (cur->left) dqL.push(cur->left);
            }
            
            // if we have some data in currentLevel vector then we need to add the data into answers
            // and clear the data so that it can again be filled for the next iteration
            if (curLevel.size() > 0)
            {
                ans.push_back(curLevel);
                curLevel.clear();
            }
        }
    }
    return ans;
}