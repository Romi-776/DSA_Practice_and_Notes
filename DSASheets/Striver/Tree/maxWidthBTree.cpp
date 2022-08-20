/*
Max Width = Max no. of possible nodes between any two nodes at the same level in binary tree

INTUITION
We're assigning indices to each node and using that we're checking that which node can have possible
max no. of nodes in between the first and last node present on that level using those indices
if root is at 0th index then
its left node should be at 0th index and right at 1st index
*/
// T.C = O(N), S.C = O(N)
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int maxWidth = 0;
        if (root)
        {
            deque<TreeNode *> dq;
            root->val = 0, maxWidth = 1;
            dq.push_back(root);

            while (dq.size())
            {
                int sz = dq.size();
                // will use it to prevent overflow
                int min = root->val;
                while (sz--)
                {
                    root = dq.front();
                    // using min so that each level will start from 0 to max no. of nodes of that level
                    root->val -= min;
                    dq.pop_front();

                    // 0 based indexing
                    if (root->left)
                        root->left->val = root->val * 2, dq.push_back(root->left);
                    if (root->right)
                        root->right->val = root->val * 2 + 1, dq.push_back(root->right);
                }
                if (dq.size() > 1)
                    maxWidth = max(maxWidth, dq.back()->val - dq.front()->val + 1);
            }
        }
        return maxWidth;
    }
};