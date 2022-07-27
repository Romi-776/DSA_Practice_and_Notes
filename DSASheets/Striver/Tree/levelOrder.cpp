// (BFS using Queue)
// 5. Level Order Traversal
//  Add the nodes at each level according to their levels into the queue
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