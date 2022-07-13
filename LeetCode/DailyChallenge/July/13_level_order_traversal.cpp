// Binary Tree Level Order Traversal - https://leetcode.com/problems/binary-tree-level-order-traversal/

// T.C = O(V+E), S.C = O(V+E) + O(V) + O(V)
/*
INTUITION
BFS TRAVERSAL
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root)
        {
            queue<TreeNode *> q;

            q.push(root);
            while (q.size())
            {
                vector<int> v;
                int sz = q.size();
                while (sz--)
                {
                    root = q.front();
                    v.push_back(root->val);
                    q.pop();

                    if (root->left)
                        q.push(root->left);
                    if (root->right)
                        q.push(root->right);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};