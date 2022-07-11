// Binary Tree Right Side View - https://leetcode.com/problems/binary-tree-right-side-view/

// BFS BASED SOLUTION
// T.C = O(N), S.C = O(N)
// where N is the total number of nodes in the tree
/*
INTUITION
While BFS traversal of a tree, the rightmost node at the ith level in a binary tree
will be the ith node in the right view of the tree.
*/
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;

        if (root)
        {
            queue<TreeNode *> q;
            q.push(root);

            while (q.size())
            {
                int sz = q.size();

                for (int i = 0; i < sz; i++)
                {
                    root = q.front();
                    if (i == sz - 1)
                        ans.push_back(root->val);
                    q.pop();

                    if (root->left)
                        q.push(root->left);
                    if (root->right)
                        q.push(root->right);
                }
            }
        }

        return ans;
    }
};

// DFS BASED SOLUTION
// T.C = O(N), S.C = O(N)
/*
INTUITION
While DFS traversal and going towards right first, we're keeping in mind that whenever we're at any level where the number of nodes
at the current level is equals the size of the resultant array of nodes in rightSideView then we need to add the current node as this
will be our new node for the right side view.
*/
class Solution
{
    void rightView(TreeNode *curr, vector<int> &res, int level)
    {
        if (curr != NULL)
        {
            if (level == res.size())
                res.push_back(curr->val);
            rightView(curr->right, res, level + 1);
            rightView(curr->left, res, level + 1);
        }
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        rightView(root, res, 0);
        return res;
    }
};