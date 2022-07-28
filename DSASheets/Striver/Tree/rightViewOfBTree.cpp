/*
SIMILAR LOGIC WILL BE USED FOR LEFT VIEW WITH SOME MINOR CHANGES IN CODE.
*/

// Using BFS traversal
// by getting last node at each level from the queue
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

// Using DFS traversal
// going towards right first before moving to left and whenever we're
// at a new level then we'll add it to our answer
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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    rightView(root, res, 0);
    return res;
}