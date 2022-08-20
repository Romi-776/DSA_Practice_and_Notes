// (BFS using Queue)
// 5. Level Order Traversal
//  Add the nodes at each level according to their levels into the queue using BFS TRAVERSAL
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

// IMPLEMENTING BFS TRAVERSAL (USING DFS)
void dfs(TreeNode *curr, vector<vector<int>> &ans, int level)
{
    if (curr)
    {
        if (level >= ans.size())
            ans.push_back({});

        ans[level].push_back(curr->val);
        dfs(curr->left, ans, level + 1), dfs(curr->right, ans, level + 1);
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root)
    {
        dfs(root, ans, 0);
    }
    return ans;
}